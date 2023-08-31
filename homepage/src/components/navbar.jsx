import sw from '../../src/icons/sw.png';
import React, {useState, useEffect, useRef} from 'react';
import '../index.css'

function App() {

  const [open, setOpen] = useState(false);

  let menuRef = useRef();

  useEffect(() => {
    let handler = (e)=>{
      if(!menuRef.current.contains(e.target)){
        setOpen(false);
        console.log(menuRef.current);
      }      
    };

    document.addEventListener("mousedown", handler);

    return() =>{
      document.removeEventListener("mousedown", handler);
    }

  });

  return (
    <div className="App">
      <div className='menu-container' ref={menuRef}>
        <div className='menu-trigger' onClick={()=>{setOpen(!open)}}>
          <img src={sw}></img>
        </div>

        <div className={`dropdown-menu ${open? 'active' : 'inactive'}`} >
          <h3>Sebastian Wehmeyer</h3>
          <ul>
            <DropdownItem text = {"Home"}/>
            <DropdownItem text = {"About"}/>
            <a href="./esports/esports.tsx" ><DropdownItem text = {"eSports"}/></a>
            <a href="./socials/socials.tsx" ><DropdownItem text = {"Socials"}/></a>
            <DropdownItem text = {"Settings"}/>
          </ul>
        </div>
      </div>
    </div>
  );
}

function DropdownItem(props){
  return(
    <li className = 'dropdownItem'>
      <a> {props.text} </a>
    </li>
  );
}

export default App;
