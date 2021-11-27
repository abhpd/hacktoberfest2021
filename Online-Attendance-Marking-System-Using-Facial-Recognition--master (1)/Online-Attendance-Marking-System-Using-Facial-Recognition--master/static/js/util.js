function getUserData(user) {
    if (user.is_student) {
        $.get({
            url: "/api/student/" + user.id,
            headers: {
                Authorization: 'JWT ' + Cookies.get('access_token')
            },
            success: function (data) {
                $.extend(user, data);
                $("#user-name").text(user.student_name + " " + user.student_id)
            },
            error: function (e) {
                console.log("ERROR : ", e);
            }
        });
    } else {
        $.get({
            url: "/api/faculty/" + user.id,
            headers: {
                Authorization: 'JWT ' + Cookies.get('access_token')
            },
            success: function (data) {
                $.extend(user, data);
                $("#user-name").text(user.faculty_name + " " + user.faculty_id)
            },
            error: function (e) {
                console.log("ERROR : ", e);
            }
        });
    }
    return user;
}

function checkLoggedIn() {
    if (!Cookies.get('access_token')) {
        window.location.href = "/login";
    }
}