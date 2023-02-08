const cardArray = [
  {
    name: "jeong",
    img: "./image/wjdqls.png",
    id: null,
    done : false
  },
  {
    name: "jeong",
    img: "./image/wjdqls.png",
    id: null,       
    done : false
  },
  {
    name: "guswhd",
    img: "./image/guswhd.png",
    id: null,
    done : false
  },
  {
    name: "guswhd",
    img: "./image/guswhd.png",
    id: null,
    done : false
  },
  {
    name: "wlswn",
    img: "./image/wlswn.png",
    id: null,
    done : false
  },
  {
    name: "wlswn",
    img: "./image/wlswn.png",
    id: null,
    done : false
  },
  {
    name: "woaks",
    img: "./image/woaks.png",
    id: null,
    done : false
  },
  {
    name: "woaks",
    img: "./image/woaks.png",
    id: null,
    done : false
  },
  {
    name: "gksruf",
    img: "./image/gksruf.png",
    id: null,
    done : false
  },
  {
    name: "gksruf",
    img: "./image/gksruf.png",
    id: null,
    done : false
  }, 
  {
    name: "dkfka",
    img: "./image/dkfka.png",
    id: null,
    done : false
  },
  {
    name: "dkfka",
    img: "./image/dkfka.png",
    id: null,
    done : false
  },
];

const gameDOM = [];
let clickFirst = -1;
let clickSecond = -1;
let clickCount = 0;
let chellangeCount = 0;
let sucessCount = 0;

const getGameDOM = () => {
  const rows = document.querySelectorAll(".row");
  for (let i = 0; i < rows.length; i++) {
    gameDOM[i] = rows[i].querySelectorAll(".column");
  }
  console.log(gameDOM);
};

const setIDtoCardArray = () => {
  cardArray[0].id = "0-0";
  cardArray[1].id = "0-1";
  cardArray[2].id = "0-2";
  cardArray[3].id = "0-3";
  cardArray[4].id = "1-0";
  cardArray[5].id = "1-1";
  cardArray[6].id = "1-2";
  cardArray[7].id = "1-3";
  cardArray[8].id = "2-0";
  cardArray[9].id = "2-1";
  cardArray[10].id = "2-2";
  cardArray[11].id = "2-3";
};

const createBoard = () => {
  for (let i = 0; i < gameDOM.length; i++) {
    for (let j = 0; j < gameDOM[i].length; j++) {
      const card = document.createElement("img");
      card.setAttribute("src", "./image/Question-Mark.png");
      card.classList.add("eachImage");
      gameDOM[i][j].appendChild(card);
    }
  }
}

const setClickHistory = (location) => {
  if (clickFirst === -1) {
    clickFirst = location;
  } else {
    clickSecond = location;
  }
}

const backFlip = () => {
  const parseIdFirst = cardArray[clickFirst].id.split("-");
  const parseIdSecond = cardArray[clickSecond].id.split("-");
  setTimeout(() => {
    gameDOM[parseIdFirst[0]][parseIdFirst[1]].querySelector("img").src = "./image/Question-Mark.png";
    gameDOM[parseIdSecond[0]][parseIdSecond[1]].querySelector("img").src = "./image/Question-Mark.png";
  }, 500);
}

const isCorrect = () => {
  if (cardArray[clickFirst].name === cardArray[clickSecond].name) {
    cardArray[clickFirst].done = true;
    cardArray[clickSecond].done = true;
    sucessCount++;
  } else {
    backFlip();
  }
}

const isSucess = () => {
  if(sucessCount === 6) {
    alert(`축하합니다! ${chellangeCount / 2}회 도전만에 성공했습니다.`);
  }
}

const filp = (location) => {
  if(!cardArray[location].done) {
    setClickHistory(location);

    const parseID = cardArray[location].id.split("-");
    gameDOM[parseID[0]][parseID[1]].querySelector("img").src = cardArray[location].img;

    clickCount++;
    chellangeCount++;
    if(clickCount == 2) {
      clickCount = 0;
      isCorrect();
    }

    if (clickFirst !== -1 && clickSecond !== -1) {
      clickFirst = -1;
      clickSecond = -1;
    }
  }
  setTimeout(() => {
    isSucess();
  }, 500);  
};



onload = () => {
  getGameDOM();
  cardArray.sort(() => 0.5 - Math.random());
  setIDtoCardArray();
  createBoard();  
};