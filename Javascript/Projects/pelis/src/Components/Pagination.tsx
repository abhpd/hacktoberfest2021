import { useDispatch, useSelector } from "react-redux";
import styled from "styled-components";
import * as themeConf from "../theme";
import { NavigatePage } from "../Redux/pelisDuck";

const PaginationContainer = styled.div`
  display: flex;
  margin-left: auto;
  margin-right: 5em;
  margin-top: 1em;
  margin-bottom: 1em;
  justify-content: space-between;
  align-items: center;
`;

const BtnPagination = styled.button`
  display: flex;
  justify-content: center;
  align-items: center;
  background: ${themeConf.inputBackgroundColor};
  border: none;
  color: ${themeConf.textColor};
  width: 3em;
  height: 3em;
  cursor: pointer;
  padding: 1em;
  border-radius: 50%;
  &:not(:last-child) {
    margin-right: 1em;
  }
`;

export default function Pagination(): React.ReactElement {
  const dispatch = useDispatch();
  const total_pages = useSelector((state: any) => state.peliculas.total_pages);
  const current_page = useSelector((state: any) => state.peliculas.page);
  const nextPage = () => {
    if (current_page < total_pages) {
      dispatch(NavigatePage(current_page + 1));
    }
  };

  const prevPage = () => {
    if (current_page > 1) {
      dispatch(NavigatePage(current_page - 1));
    }
  };
  return (
    <PaginationContainer>
      <BtnPagination onClick={prevPage}>{"<"}</BtnPagination>
      <BtnPagination onClick={nextPage}>{">"}</BtnPagination>
    </PaginationContainer>
  );
}
