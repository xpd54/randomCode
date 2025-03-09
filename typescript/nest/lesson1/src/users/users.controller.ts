import { Body, Controller, Get, Param, Post } from '@nestjs/common';

@Controller('users')
export class UsersController {
  /*
  GET /users
  GET /user/:id
  POST /user
  PATCH /user/:id
  DELETE /user/:id
  */
  @Get()
  findAll() {
    return [];
  }

  @Get(':id')
  findOne(@Param('id') id: string) {
    return {id}
  }

  @Post() // 
  create(@Body() user: {}) {
    return user
  }
}
