import { Injectable } from '@nestjs/common';
import { ToDoDoc, to_do_collection } from './schema/to-do.schema';
import { Model } from 'mongoose';
import { InjectModel } from '@nestjs/mongoose';

@Injectable()
export class ToDoService {
  constructor(
    @InjectModel(to_do_collection)
    private toDoModel: Model<ToDoDoc>,
  ) {}

  async insertToDo(): Promise<ToDoDoc> {
    const newToDo = new this.toDoModel({
      subject: 'Work on',
      discription: 'Let me do all the work up',
      dueDate: new Date(),
    });

    return newToDo.save();
  }
}
