import styled from "styled-components";
import * as themeConf from "../theme";
import { NavLink } from "react-router-dom";
import { Fragment, useState } from "react";
import { useTheme } from "../ThemeManager";
import { FaBars } from "react-icons/fa";

interface IBtn {
  open: boolean;
}

const Navbar = styled.nav`
  background: ${themeConf.backgroundColor};
  border-bottom: 1px solid ${themeConf.borderColor};
  display: flex;
  justify-content: space-between;
  align-items: center;
  height: ${themeConf.navHeight};
  padding: 0 ${themeConf.navPadding};
  > svg {
    color: ${themeConf.textColor};
    margin-right: ${themeConf.navPadding};
    cursor: pointer;
    display: block;
    @media screen and (min-width: 768px) {
      display: none;
    }
  }
`;

const Button = styled.button`
  background: ${themeConf.buttonBackgroundColor};
  border: none;
  border-radius: 0.3em;
  color: ${themeConf.buttonTextColor};
  cursor: pointer;
  font-size: 0.5em;
  padding: 0.5em 1em;
`;

const NavbarBrand = styled.div`
  flex: 1;
  text-align: left;
  > a {
    color: ${themeConf.textColor};
    text-decoration: none;
    font-weight: bold;
    font-size: 1.2em;
  }
`;

const NavbarCollapse = styled.ul<IBtn>`
  list-style: none;
  margin: 0;
  @media screen and (max-width: 767px) {
    display: ${(props) => (props.open ? "flex" : "none")};
    flex-direction: column;
    justify-content: center;
    align-items: center;
    position: absolute;
    top: 0;
    left: 0;
    width: 100%;
    height: 100%;
    z-index: 1;
    background: ${themeConf.navBackgroundColor};
    > li {
      transition: all 0.3s;
      text-align: center;
      margin-bottom: 0.5em;
    }
    > li:not(:first-child) {
      padding: 0.5em;
      width: 80%;
      border-radius: 0.3em;
      border: 1px solid ${themeConf.borderColor};
    }
    > li:hover {
      background: ${themeConf.textColor};
      > a,
      span {
        color: ${themeConf.backgroundColor};
      }
    }
  }
  @media screen and (min-width: 768px) {
    display: flex;
    position: relative;
    justify-content: space-between;
    align-items: center;
    > li:last-child {
      display: none;
    }
  }
`;

const NavbarItem = styled(NavLink)`
  text-decoration: none;
  color: ${themeConf.textColor};
  display: block;
  padding: 0.5em 0.5em;
  @media screen and (min-width: 768px) {
    margin-left: 1em;
    padding: 0;
  }
`;

const NavbarClose = styled.span`
  width: 100%;
  font-weight: bold;
  height: 100%;
  cursor: pointer;
  display: block;
  color: ${themeConf.textColor};
  padding: 0.5em 0.5em;
`;

export default function Nav(): React.ReactElement {
  const [openNav, setOpenNav] = useState<boolean>(false);
  const toggleNav = (): void => setOpenNav(!openNav);
  const hideNav = (): void => setOpenNav(false);
  const theme = useTheme();

  return (
    <Fragment>
      <Navbar>
        <NavbarBrand>
          <NavbarItem to="/"> Pelis</NavbarItem>
        </NavbarBrand>
        <FaBars onClick={toggleNav} />
        <NavbarCollapse open={openNav}>
          <li>
            <Button onClick={() => theme.toggle()}>
              {theme.mode === "dark" ? (
                <span role="img">🌞</span>
              ) : (
                <span role="img">🌜</span>
              )}
            </Button>
          </li>
          <li>
            <NavbarItem to="/about" onClick={hideNav}>
              About
            </NavbarItem>
          </li>
          <li>
            <NavbarItem to="/contact" onClick={hideNav}>
              Contact
            </NavbarItem>
          </li>
          <li>
            <NavbarClose onClick={hideNav}>X</NavbarClose>
          </li>
        </NavbarCollapse>
      </Navbar>
    </Fragment>
  );
}
