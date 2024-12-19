const e = require("express");
const express = require("express");
const zod = require("zod");
const app = express();

const schema = zod.object({
    email: zod.string(),
    password: zod.z.string(),
    country: zod.z.literal("IN").or(zod.literal("US")),
    kidneys: zod.array(zod.number())
})

app.use(express.json());

app.post("/health-checkup", function (req, res) {
    const kidneys = req.body.kidneys;
    const response = schema.safeParse(kidneys);
    if (!response.success) {
        res.status(411).json({
            msg: "input is invalid"
        });
    } else {
        res.send({
            response
        })
    }
})

app.listen(3000);