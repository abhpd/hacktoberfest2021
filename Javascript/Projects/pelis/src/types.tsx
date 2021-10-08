export interface ThemeContext {
  mode: string;
  toggle(): void;
}

type ProductionCompany = {
  name: string;
  id: number;
  origin_country: string;
};

export type Movie = {
  backdrop_path: string | null;
  id: number;
  original_language: string;
  original_title: string;
  overview: string | null;
  popularity: number;
  poster_path: string | null;
  release_date: string;
  title: string;
  vote_average: number;
  vote_count: number;
  adult?: boolean;
  production_companies?: ProductionCompany[];
};
