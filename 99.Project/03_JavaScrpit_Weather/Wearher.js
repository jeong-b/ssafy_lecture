// 배경 요소
async function setReanderBackground() {
  // body의 background 주소를 넣어도 가능
  // 이번에 의도적으로 axios 요청으로 이미지 받아오기

  // blob -> 이미지, 사운드 ,비디오 등 멀티미디어를 가져올 때 사용
  const result = await axios.get("https://picsum.photos/1280/720", {
    responseType : "blob"
   });
  //console.log(result.data);

   // URL.creatObjectURL : 임시 URL을 만든다(체이지 내에서만 유효)
   // 받아온 데이터를 임시 URL을 만들어서 그 URL 바디에 넣는다.
   const imageURL = URL.createObjectURL(result.data);
   document.querySelector('body').style.backgroundImage = `url(${imageURL})`;
}

// 시간갱신
function setTime() {
  const timer = document.querySelector('.timer');
  const date = new Date();
  timer.textContent = `${date.getHours()}:${date.getMinutes()}:${date.getSeconds()}`;
  setInterval(() => { 
    const date = new Date();   
    timer.textContent = `${date.getHours()}:${date.getMinutes()}:${date.getSeconds()}`;    
  }, 1000);
}

// 메모 입력
function getMemo() {
  const memo = document.querySelector('.memo');
  memo.textContent = localStorage.getItem('todo');
}

function setMemo() {
  const memoInput = document.querySelector('.memo-input');

  memoInput.addEventListener('keyup', function (evt) {
    // ! null undifined false "" -> 부정의 의미
    // if(evt.target.value) -> 부정의 의미가 아닌경우를 통합
    // if(!evt.target.value) -> 부정의 의미인 경우    
    if ((evt.code === 'Enter' || evt.code === 'NumpadEnter') && evt.target.value) {
      // 메모를 저장
      //const memo = document.querySelector('.memo');
      //memo.textContent = evt.target.value;

      // 메모가 날아가지 않도록 저장
      // 백엔드 -> DB에 저장해서 가져오는 작업
      // 브라우저에도 간단한 저장소 개념이있다. localStorage
      localStorage.setItem('todo', evt.target.value);
      // getMemo로 분리
      getMemo();
      evt.target.value = "";
    }
  })
}

function deleteMemo() {
  // 이벤트 위임
  // 똑같은 함수를 여러개 addEventLister 가정 -> 속도 저하
  document.addEventListener('click', function (evt) {
    // localStorage를 지운다
    if (evt.target.classList.contains('memo')) {
      localStorage.removeItem('todo');
      evt.target.textContent = "";
    }
    // HTML파드를 지운다
  })
}


// 전체 실행
function allReander() {
  setReanderBackground();
  setTime();
  setMemo();
  getMemo();
  deleteMemo();

  // 5초마다 해당 콜백함수 반복
  setInterval(() => {
    setReanderBackground();
  }, 5000);
}

allReander();