import { Title } from "../StyleComponents/Title";
import * as themeConf from "../theme";
import styled from "styled-components";
import { useDispatch, useSelector } from "react-redux";
import { obtenerPeliculas } from "../Redux/pelisDuck";
import { Fragment, useState } from "react";
import { FaSearch } from "react-icons/fa";
import { Movie } from "../types";
import MovieC from "./Movie";
import Pagination from "./Pagination";
import Detail from "./Detail";

const MovieContainer = styled.div`
  display: flex;
  flex-wrap: wrap;
  justify-content: center;
`;

const Container = styled.div`
  display: flex;
  flex-direction: column;
  align-items: center;
`;

const Input = styled.input`
  width: 100%;
  color: ${themeConf.textColor};
  background-color: transparent;
  border: none;
  display: block;
  border-radius: 4px;
  flex: 1;
`;

const Form = styled.form`
  background: ${themeConf.inputBackgroundColor};
  width: 100%;
  padding: 0.3em 0.8em;
  border-radius: 4px;
  display: flex;
  align-items: center;
  margin: 1em 0;
  justify-content: space-between;
  max-width: 350px;
`;

const Button = styled.button`
  background: ${themeConf.inputBackgroundColor};
  color: ${themeConf.textColor};
  border: none;
  cursor: pointer;
  display: block;
  padding: 0.5em;
  margin: 0;
`;

export default function Home(): JSX.Element {
  const peliculas = useSelector((state: any) => state.peliculas.peliculas);
  const total_results = useSelector(
    (state: any) => state.peliculas.total_results
  );
  const current_movie = useSelector(
    (state: any) => state.peliculas.current_movie
  );
  const dispatch = useDispatch();

  const [search, setSearch] = useState<string>("");

  const handleSubmit = (e: React.FormEvent<HTMLFormElement>): void => {
    e.preventDefault();
    dispatch(obtenerPeliculas(search));
  };

  return peliculas.length < 1 ? (
    <div>
      <Title>Bienvenido a Pelis</Title>
      <small>Aqui podrás encontrar tus peliculas favoritas</small>
      <Form onSubmit={handleSubmit}>
        <Input
          onChange={(e) => setSearch(e.target.value)}
          type="text"
          value={search}
          placeholder="Buscar..."
        />
        <Button type="submit">
          <FaSearch />
        </Button>
      </Form>
    </div>
  ) : (
    <Fragment>
      {current_movie ? (
        <Detail movie={current_movie} />
      ) : (
        <Container>
          <Form onSubmit={handleSubmit}>
            <Input
              onChange={(e) => setSearch(e.target.value)}
              type="text"
              value={search}
              placeholder="Buscar..."
            />
            <Button type="submit">
              <FaSearch />
            </Button>
          </Form>
          <p>Resultados de la busqueda {total_results}</p>
          <MovieContainer>
            {peliculas.map((peli: Movie) => (
              <MovieC movie={peli} key={peli.id} />
            ))}
          </MovieContainer>
          <Pagination />
        </Container>
      )}
    </Fragment>
  );
}
