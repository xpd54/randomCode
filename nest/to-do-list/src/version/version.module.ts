import { Module } from '@nestjs/common';
import { VersionController } from './version.controller';
import { VersionService } from './version.service';
import { MongooseModule } from '@nestjs/mongoose';
import { VersionSchema, name } from './version-schema/version-schema';

@Module({
  imports: [MongooseModule.forFeature([{ name: name, schema: VersionSchema }])],
  controllers: [VersionController],
  providers: [VersionService],
})
export class VersionModule {}
