from fastapi import FastAPI, Depends, status, Response, HTTPException
from . import models, schemas, hashing
from .database import engine, SessionLocal
from sqlalchemy.orm import Session
from typing import List
from . import database
from .routers import blog

app = FastAPI()
app.include_router(blog.router)
models.Base.metadata.create_all(engine)
get_db = database.get_db


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
