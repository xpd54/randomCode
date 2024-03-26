import { Prop, Schema, SchemaFactory } from '@nestjs/mongoose';
import { HydratedDocument } from 'mongoose';
export type VersionDoc = HydratedDocument<Version>;
export const name = 'version';
@Schema()
export class Version {
  @Prop()
  version: number;
  @Prop()
  major: number;
  @Prop()
  minor: number;
  @Prop({ default: new Date() })
  time_stamp: Date;
}
export const VersionSchema = SchemaFactory.createForClass(Version);
