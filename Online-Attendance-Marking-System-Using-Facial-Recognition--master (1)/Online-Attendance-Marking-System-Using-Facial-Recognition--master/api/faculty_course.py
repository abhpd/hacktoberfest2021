from flask_jwt import jwt_required, current_identity
from flask_restful import Resource

from db.db_util import get_faculty, get_faculty_courses, get_course


class FacultyCourses(Resource):
    @jwt_required()
    def get(self, user_id):
        if user_id == current_identity.id:
            faculty = get_faculty(user_id)
            faculty_courses = get_faculty_courses(faculty["id"])
            if faculty_courses:
                courses_list = []
                for course in faculty_courses:
                    courses_list.append(get_course(course))
                return courses_list
            return {'message': 'Faculty\'s courses not found'}, 404
        else:
            return {'message': 'Current faculty is not authorized to view this student\'s courses'}, 404
