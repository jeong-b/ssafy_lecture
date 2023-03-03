/*
const express = require('express');
const app = express();
const PORT = 8080;

const cors = require("cors");
app.use(cors());

app.use(express.json());

app.get("/api/menus", (req, res) => {
  return res.json({ "TEST" : "OK", "TYPE" : "GET"});
});

app.post("/api/menus", (req, res) => {
  console.log(req.body);
  return res.json({"TEST" : "OK", "TYPE" : "POST"});
});

app.listen(PORT, () => console.log(`this server is listening on ${PORT}`));
*/

/*
*/
const express = require("express");
const app = express();
const PORT = 8080;

const cors = require("cors");
app.use(cors());

app.use(express.json());

const { pool } = require("./db");

app.get("/api/menus", async (req, res) => {
  try {
    const data = await pool.query("SELECT * FROM menus");
    if (data[0]) {
      return res.json(data[0]);
    }
  } catch (error) {
    console.log(error);
  }
});

app.post("/api/menus", async (req, res) => {
  console.log(req.body);
  try {
    const data = await pool.query(`INSERT INTO menus (menu_name, menu_description, menu_img_link)
    VALUES (?, ?, ?)`, [req.body.menu_name, req.body.menu_description, ""]);
    
    return res.json(data);
  } catch (error) {
    console.log(error);
  }
});

app.listen(PORT, () => console.log(`this server is listening on ${PORT}`));