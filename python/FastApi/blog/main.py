from fastapi import FastAPI, Depends, status, Response, HTTPException
from . import models, schemas, hashing
from .database import engine, SessionLocal
from sqlalchemy.orm import Session
from typing import List

app = FastAPI()
models.Base.metadata.create_all(engine)


def get_db():
    db = SessionLocal()
    try:
        yield db
    finally:
        db.close()


@app.post("/blog", status_code=status.HTTP_201_CREATED, tags=["blogs"])
def create(request: schemas.Blog, db: Session = Depends(get_db)):
    new_blog = models.Blog(title=request.title, body=request.body)
    db.add(new_blog)
    db.commit()
    db.refresh(new_blog)
    return new_blog


@app.get(
    "/blog/{id}",
    status_code=status.HTTP_200_OK,
    response_model=schemas.ShowBlog,
    tags=["blogs"],
)
def show_id(id, response: Response, db: Session = Depends(get_db)):
    blog = db.query(models.Blog).filter(models.Blog.id == id).first()
    if not blog:
        raise HTTPException(
            status_code=status.HTTP_404_NOT_FOUND,
            detail=f"Blog with the id {id} is not avaialble",
        )
    return blog


@app.delete("/blog/{id}", status_code=status.HTTP_204_NO_CONTENT, tags=["blogs"])
def delete_blog(id, db: Session = Depends(get_db)):

    blog = db.query(models.Blog).filter(models.Blog.id == id)
    if not blog:
        raise HTTPException(
            status.HTTP_404_NOT_FOUND, detail=f"Blog with id {id} not found"
        )
    blog.delete(synchronize_session=False)
    db.commit()
    return "done"


@app.put("/blog/{id}", status_code=status.HTTP_202_ACCEPTED, tags=["blogs"])
def update(id, request: schemas.Blog, db: Session = Depends(get_db)):
    blog = db.query(models.Blog).filter(models.Blog.id == id)
    if not blog.first():
        raise HTTPException(
            status.HTTP_404_NOT_FOUND, detail=f"Blog with id {id} not found"
        )
    blog.update({"title": request.title, "body": request.body})
    db.commit()
    return "updated"


@app.get("/blog", response_model=List[schemas.ShowBlog], tags=["blogs"])
def get_all_blog(db: Session = Depends(get_db)):
    blogs = db.query(models.Blog).all()
    return blogs


@app.post("/user", response_model=schemas.ShowUser, tags=["user"])
def create_user(request: schemas.User, db: Session = Depends(get_db)):
    hashed_password = hashing.Hash.bcrypt(request.password)
    new_user = models.User(
        name=request.name, email=request.email, password=hashed_password
    )
    db.add(new_user)
    db.commit()
    db.refresh(new_user)
    return new_user


@app.get(
    "/user/{id}",
    status_code=status.HTTP_200_OK,
    response_model=schemas.ShowUser,
    tags=["user"],
)
def get_user(id, db: Session = Depends(get_db)):
    user = db.query(models.User).filter(models.User.id == id).first()
    if not user:
        raise HTTPException(
            status_code=status.HTTP_404_NOT_FOUND,
            detail=f"User with the id {id} is not avaialble",
        )
    return user
