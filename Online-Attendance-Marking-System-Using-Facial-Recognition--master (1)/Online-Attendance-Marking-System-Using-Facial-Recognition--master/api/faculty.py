from flask_jwt import jwt_required, current_identity
from flask_restful import Resource

from db.db_util import get_faculty


class Faculty(Resource):
    @jwt_required()
    def get(self, user_id):
        if current_identity.id == user_id:
            faculty = get_faculty(user_id)
            if faculty:
                return faculty
            else:
                return {'message': 'Faculty not found'}, 404
        else:
            return {'message': 'You are not authorized to view this faculty\'s details'}, 404
