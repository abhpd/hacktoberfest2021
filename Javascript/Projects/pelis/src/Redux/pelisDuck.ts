import { clienteAxios } from "../Config/axios";
import { Movie as IPelicula } from "../types";

type PeliculaState = {
  peliculas: IPelicula[];
  current_movie: null | IPelicula;
  searched: string;
  page: number;
  total_pages: number;
  total_results: number;
};

type TheMVDBResponse = {
  page: number;
  results: IPelicula[];
  total_results: number;
  total_pages: number;
};

type PeliculaAction = {
  searched: string;
  type: string;
  peliculas: IPelicula[] | [];
  page: number;
  total_results: number;
  current_movie: null | IPelicula;
  total_pages: number;
};

type SelectionType = {
  type: string;
  current_movie: IPelicula | null;
};

type DispatchType = (args: PeliculaAction) => PeliculaAction;
type DispatchTypeSelection = (args: SelectionType) => SelectionType;

const dataInicial: PeliculaState = {
  current_movie: null,
  searched: "",
  peliculas: [],
  page: 0,
  total_pages: 0,
  total_results: 0,
};

const OBTENER_PELICULAS = "OBTENER_PELICULAS";
const OBTENER_PELICULAS_ERROR = "OBTENER_PELICULAS_ERROR";
const SELECCIONAR_PELICULA = "SELECCIONAR_PELICULA";
const DESELECCIONAR_PELICULA = "DESELECCIONAR_PELICULA";

export default function reducer(
  state: PeliculaState = dataInicial,
  action: PeliculaAction
): PeliculaState {
  switch (action.type) {
    case OBTENER_PELICULAS:
      return {
        ...state,
        peliculas: action.peliculas,
        current_movie: null,
        page: action.page,
        total_pages: action.total_pages,
        total_results: action.total_results,
        searched: action.searched,
      };
    case OBTENER_PELICULAS_ERROR:
      return {
        ...state,
        peliculas: [],
        page: 0,
        total_pages: 0,
        total_results: 0,
        searched: action.searched,
      };
    case SELECCIONAR_PELICULA:
      return {
        ...state,
        current_movie: action.current_movie,
      };
    case DESELECCIONAR_PELICULA:
      return {
        ...state,
        current_movie: null,
      };
    default:
      return state;
  }
}

export const obtenerPeliculas =
  (data: string, page = 1) =>
  async (dispatch: DispatchType) => {
    try {
      const response = await clienteAxios.get(
        `search/movie?api_key=${process.env.REACT_APP_API_KEY}&query=${data}&page=${page}`
      );
      const themoviedbData: TheMVDBResponse = response.data;
      dispatch({
        type: OBTENER_PELICULAS,
        searched: data,
        peliculas: themoviedbData.results,
        page: themoviedbData.page,
        current_movie: null,
        total_results: themoviedbData.total_results,
        total_pages: themoviedbData.total_pages,
      });
    } catch (error) {
      dispatch({
        type: OBTENER_PELICULAS_ERROR,
        searched: data,
        peliculas: [],
        page: 0,
        current_movie: null,
        total_pages: 0,
        total_results: 0,
      });
      console.log(error);
    }
  };

export const NavigatePage =
  (page: number) =>
  (dispatch: DispatchType, getState: () => { peliculas: PeliculaState }) => {
    const { searched } = getState().peliculas;
    obtenerPeliculas(searched, page)(dispatch);
  };

export const selectMovie =
  (movie: IPelicula) => (dispatch: DispatchTypeSelection) => {
    obtenerDetallePelicula(movie.id)(dispatch);
  };

export const deselectMovie = () => (dispatch: DispatchTypeSelection) => {
  dispatch({
    type: DESELECCIONAR_PELICULA,
    current_movie: null,
  });
};

export const obtenerDetallePelicula =
  (id: number) => async (dispatch: DispatchTypeSelection) => {
    const response = await clienteAxios.get(
      `movie/${id}?api_key=${process.env.REACT_APP_API_KEY}`
    );
    const movie: IPelicula = response.data;
    dispatch({
      type: SELECCIONAR_PELICULA,
      current_movie: movie,
    });
  };
