import { Injectable } from '@nestjs/common';
import { InjectModel } from '@nestjs/mongoose';
import { VersionDoc, name } from './version-schema/version-schema';
import { Model } from 'mongoose';

@Injectable()
export class VersionService {
  constructor(
    @InjectModel(name)
    private versionModel: Model<VersionDoc>,
  ) {}

  async setApplicationVersion(): Promise<VersionDoc> {
    const newApplicationVersion = await new this.versionModel({
      version: 1,
      major: 2,
      minor: 3,
    });
    return await newApplicationVersion.save();
  }

  async getApplicationVersion(): Promise<VersionDoc> {
    // will read application version from database
    const applicationVersion = await this.versionModel.findOne({});
    return applicationVersion;
  }
}
