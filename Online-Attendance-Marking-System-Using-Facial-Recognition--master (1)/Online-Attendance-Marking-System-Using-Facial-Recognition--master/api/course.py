from flask_jwt import jwt_required, current_identity
from flask_restful import Resource

from db.db_util import has_enrolled_course, does_teach_course, get_course, has_ongoing_class


class CourseApi(Resource):
    @jwt_required()
    def get(self, course_id):
        if current_identity.is_student and has_enrolled_course(course_id, current_identity.id) \
                or current_identity.is_faculty and does_teach_course(course_id, current_identity.id):
            course = get_course(course_id)
            if course:
                course["is_ongoing"] = has_ongoing_class(course_id)
                return course
            else:
                return {'message': 'Course not found'}, 404
        else:
            return {'message': 'You are not authorized to view this Course\'s details'}, 404
