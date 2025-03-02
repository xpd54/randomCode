from fastapi import FastAPI
from typing import Optional
from pydantic import BaseModel
import uvicorn

app = FastAPI()


@app.get("/")
def index():
    return {"data": {"name": "ravi"}}


@app.get("/about")
def about():
    return {"data": "about page"}


@app.get("/blog")
def blog(limit: int = 10, published: bool = False, sort: Optional[str] = None):
    if published:
        return {"data": f"{limit} published all blog posts"}
    else:
        return {"data": f"{limit} all blog posts"}


@app.get("/blog/unpublished")
def unpublished():
    return {"data": "all unpublished blogs"}


@app.get("/blog/{id}")
def show(id):
    return {"data": id}


@app.get("/blog/{id}/comments")
def comments(id: int):
    return {"data": {"comments": {"1", "2", id}}}


class Blog(BaseModel):
    title: str
    body: str
    published_at: Optional[bool]


@app.post("/blog")
def create_blog(request: Blog):
    return {"data": f"Blog has been created with title as {request.title}"}


if __name__ == "__main__":
    uvicorn.run(app, host="127.0.0.1", port=9000)
