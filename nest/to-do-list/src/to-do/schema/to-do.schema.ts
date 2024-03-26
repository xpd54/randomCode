import { Prop, Schema, SchemaFactory } from '@nestjs/mongoose';
import { HydratedDocument } from 'mongoose';

@Schema()
export class ToDo {
  @Prop()
  subject: string;
  @Prop()
  discription: string;
  @Prop({ default: new Date() })
  creationDate: Date;
  @Prop()
  dueDate: Date;
}
export const to_do_collection = 'todo';
export type ToDoDoc = HydratedDocument<ToDo>;
export const ToDoSchema = SchemaFactory.createForClass(ToDo);
