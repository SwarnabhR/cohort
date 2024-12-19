const mongoose = require("mongoose");
const express = require("express");
const app = express();

app.use(express.json());

mongoose.connect(
    "mongodb+srv://admin:Gappu%4015R@cluster0.fbxyx.mongodb.net/",
);

const User = mongoose.model('Users', { name: String, email: String, password: String });

app.post("/signup", async function (req, res) {
    const username = req.body.username;
    const password = req.body.password;
    const name = req.body.name;

    const existingUser = await User.findOne({ email: useraname });

    if (existingUser) {
        return res.status(400).json({
            msg: "User already exists",
        });
    }

    const user = new User({
        name: name,
        email: username,
        password: password,
    });

    user.save();
    res.json({
        msg: "User created successfully"
    })
});

app.listen(3000); 