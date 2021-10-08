import { FaArrowLeft } from "react-icons/fa";
import { useDispatch } from "react-redux";
import { deselectMovie } from "../Redux/pelisDuck";
import { Movie as IMovie } from "../types";
import styled from "styled-components";
import { MovieImage } from "../StyleComponents/MovieImage";

const ContainerDetail = styled.div<{ image: string }>`
  display: flex;
  flex-direction: column;
  width: 90%;
  justify-content: center;
  border-radius: 4px;
  height: 100%;
  padding: 2em;
  background-image: url(${(props) => props.image});
  background-size: cover;
  background-position: center;
  background-repeat: no-repeat;
  position: relative;
  &::after {
    content: "";
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    background-color: rgba(255, 255, 255, 0.6);)};
  }
  > * {
    z-index: 100;
  }
`;

const Description = styled.p`
  font-size: 1.2em;
  text-align: justify;
  color: #000;
  margin-top: 0.2em;
`;

const BackButton = styled.button`
  background: #333;
  color: white;
  padding: 0.4em;
  height: 2em;
  width: 2em;
  display: flex;
  justify-content: center;
  align-items: center;
  border-radius: 50%;
  border: none;
`;

const DivDetail = styled.div`
  display: flex;
  width: 100%;
  margin: 0 auto;
  margin-top: 1em;
  > img {
    margin-right: 2em;
  }
  @media (max-width: 600px) {
    flex-direction: column;
    align-items: center;
  }
`;

const Paragraph = styled.p`
  color: #000;
  font-size: 1.2em;
  margin-top: 0.5em;
  text-align: left;
`;
export default function Detail({
  movie,
}: {
  movie: IMovie;
}): React.ReactElement {
  const dispatch = useDispatch();
  return (
    <ContainerDetail
      image={
        movie.poster_path
          ? process.env.REACT_APP_URL_BACKDROP + movie.poster_path
          : "https://www.themoviedb.org/assets/2/v4/glyphicons/basic/glyphicons-basic-38-picture-grey-c2ebdbb057f2a7614185931650f8cee23fa137b93812ccb132b9df511df1cfac.svg"
      }
    >
      <BackButton onClick={() => dispatch(deselectMovie())}>
        <FaArrowLeft />
      </BackButton>
      <DivDetail>
        <MovieImage
          src={
            movie.backdrop_path
              ? process.env.REACT_APP_URL_BACKDROP + movie.backdrop_path
              : "https://www.themoviedb.org/assets/2/v4/glyphicons/basic/glyphicons-basic-38-picture-grey-c2ebdbb057f2a7614185931650f8cee23fa137b93812ccb132b9df511df1cfac.svg"
          }
          alt={"Imagen de la pelicula " + movie.title}
        />
        <div>
          <h1 style={{ textAlign: "left", fontSize: "2em", color: "black" }}>
            {movie.title}
          </h1>
          <Description>
            Descripcion: <br />
            {movie.overview}
          </Description>
          {movie.adult ? <Paragraph>Solo adultos</Paragraph> : null}
          <Paragraph>Idioma : {movie.original_language}</Paragraph>
          <Paragraph>Votos totales : {movie.vote_count}</Paragraph>
          <Paragraph>Fecha de salida: {movie.release_date}</Paragraph>
          {movie.production_companies ? (
            <Paragraph>
              Compañias de produccion:{" "}
              {movie.production_companies
                ?.map((company) => company.name)
                .join(", ")}
            </Paragraph>
          ) : null}
        </div>
      </DivDetail>
    </ContainerDetail>
  );
}
