from fastapi import APIRouter, Depends, status, Response, HTTPException
from .. import schemas, database, models, hashing
from sqlalchemy.orm import Session
from typing import List

router = APIRouter()


@router.post("/user", response_model=schemas.ShowUser, tags=["user"])
def create_user(request: schemas.User, db: Session = Depends(database.get_db)):
    hashed_password = hashing.Hash.bcrypt(request.password)
    new_user = models.User(
        name=request.name, email=request.email, password=hashed_password
    )
    db.add(new_user)
    db.commit()
    db.refresh(new_user)
    return new_user


@router.get(
    "/user/{id}",
    status_code=status.HTTP_200_OK,
    response_model=schemas.ShowUser,
    tags=["user"],
)
def get_user(id: int, db: Session = Depends(database.get_db)):
    user = db.query(models.User).filter(models.User.id == id).first()
    if not user:
        raise HTTPException(status_code=status.HTTP_404_NOT_FOUND)
