const express = require("express");
const morgan = require("morgan");
const cors = require("cors");

const app = express();
const PORT = 8080;

app.use(express.json());
app.use(morgan("dev"));
app.use(cors());

const { pool } = require("./db");

// GET - menus 전체 조회
app.get("/api/menus", async (req, res) => {
  try {
    const data = await pool.query("SELECT * FROM menus");

    if (data[0]) {
      return res.json(data[0]);
    }
  } catch (error) {
    return res.json({
      success: false,
      message: "전체 메뉴 조회에 실패하였습니다.",
    });
  }
});

// GET - menus 지정 항목 조회
app.get("/api/menus/:id", async (req, res) => {
  try {
    const data = await pool.query(
      `
      SELECT * FROM menus 
      WHERE id = ${req.params.id}
      `
    );

    if (!data[0].length) {
      return res.json({
        success: false,
        message: "해당 메뉴 조회에 실패하였습니다.(해당id없음)",
      });
    }

    if (data[0][0]) {
      return res.json(data[0][0]);
    }
  } catch (error) {
    return res.json({
      success: false,
      message: "해당 메뉴 조회에 실패하였습니다.",
    });
  }
});

// POST - menus 항목 추가
app.post("/api/menus", async (req, res) => {
  try {
    if (
      req.body.name === undefined ||
      req.body.description === undefined ||
      req.body.img_src === undefined
    ) {
      return res.json({
        success: false,
        message: "메뉴 등록에 실패하였습니다.(키값오류)",
      });
    }

    const data = await pool.query(
      `
      INSERT INTO menus 
      (name, description, img_src) 
      VALUES 
      ("${req.body.name}", "${req.body.description}", "${req.body.img_src}")
      `
    );

    const menu = await pool.query(
      `
      SELECT name, description, img_src FROM menus
      WHERE id = ${data[0].insertId}
      `
    );

    if (data[0]) {
      return res.json({
        success: true,
        message: "메뉴 등록에 성공하였습니다.",
        name: menu[0][0].name,
        description: menu[0][0].description,
        img_src: menu[0][0].img_src,
      });
    }
  } catch (error) {
    return res.json({
      success: false,
      message: "메뉴 등록에 실패하였습니다.",
    });
  }
});

// PATCH - menus 정보 수정
app.patch("/api/menus/:id", async (req, res) => {
  try {
    if (
      req.body.name === undefined ||
      req.body.description === undefined ||
      req.body.img_src === undefined
    ) {
      return res.json({
        success: false,
        message: "메뉴 변경에 실패하였습니다.(키값오류)",
      });
    }

    const data = await pool.query(
      `
      UPDATE menus 
      SET name="${req.body.name}",
      description="${req.body.description}",
      img_src="${req.body.img_src}"
      WHERE id=${req.params.id}
      `
    );

    const menu = await pool.query(
      `
      SELECT name, description, img_src FROM menus
      WHERE id = ${req.params.id}
      `
    );

    if (data[0].affectedRows === 0) {
      return res.json({
        success: true,
        message: "이미 삭제된 메뉴입니다.",
      });
    }

    if (data[0].changedRows !== 0) {
      return res.json({
        success: true,
        message: "메뉴 변경에 성공하였습니다.",
        name: menu[0][0].name,
        description: menu[0][0].description,
        img_src: menu[0][0].img_src,
      });
    }

    if (data[0].changedRows === 0) {
      return res.json({
        success: true,
        message: "변경된 내용이 없습니다.",
      });
    }
  } catch (error) {
    return res.json({
      success: false,
      message: "메뉴 변경에 실패하였습니다.",
    });
  }
});

// DELETE - menus 항목 삭제
app.delete("/api/menus/:id", async (req, res) => {
  try {
    const data = await pool.query(
      `
      DELETE FROM menus WHERE id=${req.params.id}
      `
    );

    if (data[0].affectedRows !== 0) {
      return res.json({
        success: true,
        message: "메뉴 삭제에 성공하였습니다.",
      });
    }

    if (data[0].affectedRows === 0) {
      return res.json({
        success: true,
        message: "이미 삭제된 메뉴입니다.",
      });
    }
  } catch (error) {
    return res.json({
      success: false,
      message: "메뉴 삭제에 실패하였습니다.",
    });
  }
});

// GET - orders 전체 조회
app.get("/api/orders", async (req, res) => {
  try {
    const data = await pool.query(
      `
      SELECT o.id, m.name, o.quantity, o.request_detail
      FROM orders AS o
      INNER JOIN menus AS m
      ON o.menus_id = m.id
      `
    );

    if (data[0]) {
      return res.json(data[0]);
    }
  } catch (error) {
    return res.json({
      success: false,
      message: "전체 주문 내역 조회에 실패하였습니다.",
    });
  }
});

// GET - orders 지정 항목 조회
app.get("/api/orders/:id", async (req, res) => {
  try {
    const data = await pool.query(
      `
      SELECT o.id, m.name, o.quantity, o.request_detail
      FROM orders AS o
      INNER JOIN menus AS m
      ON o.menus_id = m.id
      WHERE o.id=${req.params.id}
      `
    );
    if (!data[0].length) {
      return res.json({
        success: false,
        message: "해당 주문 내역 조회에 실패하였습니다.(해당id없음)",
      });
    }
    if (data[0][0]) {
      return res.json(data[0][0]);
    }
  } catch (error) {
    return res.json({
      success: false,
      message: "해당 메뉴 목록 조회에 실패하였습니다.",
    });
  }
});

// POST - orders 항목 추가
app.post("/api/orders", async (req, res) => {
  try {
    if (
      req.body.quantity === undefined ||
      req.body.request_detail === undefined ||
      req.body.menus_id === undefined
    ) {
      return res.json({
        success: false,
        message: "메뉴 등록에 실패하였습니다.(키값오류)",
      });
    }

    const data = await pool.query(
      `
      INSERT INTO orders
      (quantity, request_detail, menus_id)
      VALUES
      ("${req.body.quantity}", "${req.body.request_detail}", "${req.body.menus_id}")
      `
    );

    const order = await pool.query(
      `
      SELECT m.name, o.quantity, o.request_detail
      FROM orders AS o
      INNER JOIN menus AS m
      ON o.menus_id = m.id
      WHERE o.id=${data[0].insertId}
      `
    );

    if (data[0]) {
      return res.json({
        success: true,
        message: "주문 등록에 성공하였습니다.",
        name: order[0][0].name,
        quantity: order[0][0].quantity,
        request_detail: order[0][0].request_detail,
      });
    }
  } catch (error) {
    return res.json({
      success: false,
      message: "주문 등록에 실패하였습니다.",
    });
  }
});

// PATCH - order 항목 수정
app.patch("/api/orders/:id", async (req, res) => {
  try {
    if (
      req.body.quantity === undefined ||
      req.body.request_detail === undefined ||
      req.body.menus_id === undefined
    ) {
      return res.json({
        success: false,
        message: "메뉴 등록에 실패하였습니다.(키값오류)",
      });
    }

    const data = await pool.query(
      `
      UPDATE orders 
      SET quantity="${req.body.quantity}",
      request_detail="${req.body.request_detail}",
      menus_id="${req.body.menus_id}"
      WHERE id=${req.params.id}
      `
    );

    const order = await pool.query(
      `
      SELECT m.name, o.quantity, o.request_detail
      FROM orders AS o
      INNER JOIN menus AS m
      ON o.menus_id = m.id
      WHERE o.id=${req.params.id}
      `
    );

    if (data[0].affectedRows === 0) {
      return res.json({
        success: true,
        message: "이미 삭제된 주문입니다.",
      });
    }

    if (data[0].changedRows !== 0) {
      return res.json({
        success: true,
        message: "주문 수정에 성공하였습니다.",
        name: order[0][0].name,
        quantity: order[0][0].quantity,
        request_detail: order[0][0].request_detail,
      });
    }

    if (data[0].changedRows === 0) {
      return res.json({
        success: true,
        message: "수정된 내용이 없습니다.",
      });
    }
  } catch (error) {
    return res.json({
      success: false,
      message: "주문 수정에 실패하였습니다.",
    });
  }
});

// DELETE - orders 항목 삭제
app.delete("/api/orders/:id", async (req, res) => {
  try {
    const data = await pool.query(
      `
      DELETE FROM orders WHERE id=${req.params.id}
      `
    );

    if (data[0].affectedRows !== 0) {
      return res.json({
        success: true,
        message: "주문 삭제에 성공하였습니다.",
      });
    }

    if (data[0].affectedRows === 0) {
      return res.json({
        success: true,
        message: "이미 삭제된 주문입니다.",
      });
    }
  } catch (error) {
    return res.json({
      success: false,
      message: "주문 삭제에 실패하였습니다.",
    });
  }
});

app.listen(PORT, () => console.log(`this server is listening on ${PORT}`));
