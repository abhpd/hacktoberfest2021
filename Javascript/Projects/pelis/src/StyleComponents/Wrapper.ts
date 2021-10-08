import styled from "styled-components";
import * as themeConf from "../theme";

export const Wrapper = styled.div`
  background-color: ${themeConf.backgroundColor};
  color: ${themeConf.textColor};
  text-align: center;
  min-height: calc(100vh - ${themeConf.navHeight});
  display: flex;
  flex-direction: column;
  align-items: center;
  justify-content: center;
`;
