import { Module } from '@nestjs/common';
import { ToDoController } from './to-do.controller';
import { ToDoService } from './to-do.service';
import { MongooseModule } from '@nestjs/mongoose';
import { ToDoSchema, to_do_collection } from './schema/to-do.schema';

@Module({
  imports: [
    MongooseModule.forFeature([{ name: to_do_collection, schema: ToDoSchema }]),
  ],
  controllers: [ToDoController],
  providers: [ToDoService],
})
export class ToDoModule {}
