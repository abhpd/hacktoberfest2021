# Pelis

Application which will allow you to obtain movies that you are looking for. TheMovieDB api is used and you can use it to improve the frontend design including its functionality so that you can display it in your portfolio.

## Technologies

- React (TypeScript, StyleComponents)
- Docker

## Raise the development environment

To raise the development environment we will have to clone the code:

```
  git clone https://github.com/jordanrjdev/pelis.git
```

Now is the time to head to the project route

```
  cd /path/yourproyect
```

Installing the dependencies:

```
  npm i
```

Up the application with the command:

```
  npm start
```

## Lift the development environment with docker

To build the application with docker we will have to clone the repository as we saw before and go to the root of our project.
Once located in the root directory of the project we must execute the command:

```
  docker-compose up
```

Now we have to see our application in the browser at `localhost: 3000`

## Recommendations

> Remember in the .env file to put your api key of the TheMovieDb application to be able to use the api resources.

## Ideas for new features

- Add list of favorite movies

- Add lazy loading

- Add a loading component

- Add the option to search for series and soap operas

Made with ❤️ by Jordan Jaramillo
