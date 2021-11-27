$(document).ready(function () {
    $("#btnSubmit").click(function (event) {

        //stop submit the form, we will post it manually.
        event.preventDefault();

        //get data
        const formData = {
            "username": $('input[name=student_id]').val(),
            "password": $('input[name=password]').val(),
        };

        // disabled the submit button
        $("#btnSubmit").prop("disabled", true);

        $.post({
            url: "/auth",
            data: JSON.stringify(formData),
            dataType: "json",
            contentType: "application/json",
            success: function (data) {
                $("#output").text("Login Successful");
                window.location.href = "/home";
                Cookies.set('access_token', data.access_token, { expires: 7, secure: true});
                $("#btnSubmit").prop("disabled", false);
            },
            error: function (e) {
                $("#output").text(e.responseJSON["description"]);
                console.log("ERROR : ", e);
                $("#btnSubmit").prop("disabled", false);
            }
        });
    });
});