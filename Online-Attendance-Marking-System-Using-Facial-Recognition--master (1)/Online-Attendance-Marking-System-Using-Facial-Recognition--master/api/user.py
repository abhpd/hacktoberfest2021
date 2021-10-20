import json

from flask_jwt import jwt_required, current_identity
from flask_restful import Resource, reqparse

from db.db_util import get_connection


class User:
    def __init__(self, _id, username, password, is_student):
        self.id = _id
        self.username = username
        self.password = password
        self.is_student = is_student == 1
        self.is_faculty = not self.is_student

    @classmethod
    def find_by_username(cls, username):
        connection = get_connection()
        cursor = connection.cursor()

        query = 'SELECT * FROM user WHERE username=?'
        result = cursor.execute(query, (username,))
        row = result.fetchone()
        if row:
            user = cls(*row)
        else:
            user = None

        connection.close()
        return user

    @classmethod
    def find_by_id(cls, _id):
        connection = get_connection()
        cursor = connection.cursor()

        query = 'SELECT * FROM user WHERE id=?'
        result = cursor.execute(query, (_id,))
        row = result.fetchone()
        if row:
            user = cls(*row)
        else:
            user = None

        connection.close()
        return user


class UserApi(Resource):
    @jwt_required()
    def get(self):
        user = {
            'id': current_identity.id,
            'username': current_identity.username,
            'is_student': current_identity.is_student,
        }
        return user


class UserRegister(Resource):
    parser = reqparse.RequestParser()
    parser.add_argument('username',
                        type=str,
                        required=True,
                        help='This field cannot be left blank.'
                        )
    parser.add_argument('password',
                        type=str,
                        required=True,
                        help='This field cannot be left blank.'
                        )

    def post(self):
        data = self.parser.parse_args()

        if User.find_by_username(data['username']):
            return {'message': 'A user with same username exists'}, 400

        connection = get_connection()
        cursor = connection.cursor()

        query = 'INSERT INTO user VALUES (NULL, ?, ?)'
        cursor.execute(query, (data['username'], data['password']))

        connection.commit()
        connection.close()

        return {'message': 'User created successfully.'}, 201
