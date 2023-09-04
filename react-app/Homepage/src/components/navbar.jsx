import sw from "../../assets/sw.png";
import React, { useState, useEffect, useRef } from "react";
import "../css/style.css";
import DarkMode from "./darkmode";

function Navbar() {

  const [open, setOpen] = useState(false);
  let menuRef = useRef();

  useEffect(() => {
    let handler = e => {
      if (!menuRef.current.contains(e.target)) {
        setOpen(false);
        console.log(menuRef.current);
      }
    };

    document.addEventListener("mousedown", handler);

    return () => {
      document.removeEventListener("mousedown", handler);
    };
  });

  return (
    <div className="App">
      <div className="menu-container" ref={menuRef}>
        <div className="menu-trigger"onClick={() => {setOpen(!open);}}>
          <img src={sw} alt="Dropdown"></img>
        </div>
        <div className={`dropdown-menu ${open ? "active" : "inactive"}`}>
          <h3>Sebastian Wehmeyer</h3>
          <ul>
            <a href="/"><DropdownItem text={"Home"} /></a>
            <a href="/about.html"><DropdownItem text={"About"} /></a>
            <a href="/esports.html"><DropdownItem text={"eSports"} /></a>
            <a href="/socials.html"><DropdownItem text={"Socials"} /></a>
            <a href="/quotes.html"><DropdownItem text={"Quotes"} /></a>
            <DropdownDarkMode />
          </ul>
        </div>
      </div>
    </div>
  );
}

function DropdownItem(props) {
  return (
    <li className="dropdownItem">
      <div> {props.text} </div>
    </li>
  );
}

function DropdownDarkMode() {
  return (
    <li className="dropdownItem">
      <DarkMode />
    </li>
  );
}

export default Navbar;
