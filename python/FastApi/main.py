from fastapi import FastAPI

app = FastAPI()


@app.get("/")
def index():
    return {"data": {"name": "ravi"}}


@app.get("/about")
def about():
    return {"data": "about page"}


@app.get("/blog/unpublished")
def unpublished():
    return {"data": "all unpublished blogs"}


@app.get("/blog/{id}")
def show(id):
    return {"data": id}


@app.get("/blog/{id}/comments")
def comments(id: int):
    return {"data": {"comments": {"1", "2", id}}}
