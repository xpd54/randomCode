import { Module } from '@nestjs/common';
import { AppController } from './app.controller';
import { AppService } from './app.service';
import { VersionModule } from './version/version.module';
import { MongooseModule } from '@nestjs/mongoose';

@Module({
  imports: [
    VersionModule,
    MongooseModule.forRoot('mongodb://localhost:27017', { dbName: 'ToDo' }),
  ],
  controllers: [AppController],
  providers: [AppService],
})
export class AppModule {}
