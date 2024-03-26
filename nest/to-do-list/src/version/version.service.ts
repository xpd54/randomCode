import { Injectable } from '@nestjs/common';
import { ApplicationVersionDto } from './dto/application-version.dto/application-version.dto';

@Injectable()
export class VersionService {
  constructor() {}
  async getApplicationVersion(): Promise<ApplicationVersionDto> {
    // will read application version from database
    const version = new ApplicationVersionDto()
    version.version = 10;
    version.time_stamp = new Date();
    return version;
  }
}
