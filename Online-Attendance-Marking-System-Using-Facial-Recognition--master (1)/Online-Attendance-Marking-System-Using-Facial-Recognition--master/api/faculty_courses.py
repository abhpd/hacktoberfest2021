from flask_jwt import jwt_required, current_identity
from flask_restful import Resource

from db.db_util import get_faculty_courses, get_course


class FacultyCourses(Resource):
    @jwt_required()
    def get(self, user_id):
        if user_id == current_identity.id:
            faculty_courses = get_faculty_courses(user_id)
            if faculty_courses:
                courses_list = []
                for course in faculty_courses:
                    courses_list.append(get_course(course))
                return courses_list
            else:
                return {'message': 'Faculty\'s courses not found'}, 404
        else:
            return {'message': 'You are not authorized to view this faculty\'s courses'}, 404
