const puppeteer = require('puppeteer');

const main = async() => {
  // browser
  const browser = await puppeteer.launch({
    headless: false
  }); 

  // page
  const page = await browser.newPage();

  // page goto
  await page.goto("https://www.google.co.kr");

  //
  await page.evaluate(() => {
    document.querySelector('.gLFyf').value = '치킨';
    document.querySelector('.gNO89b').click();
  })

  await page.waitForSelector('.GLcBOb');
  await page.screenshot({path: "치킨.jpg", fullPage: true});
}

main();