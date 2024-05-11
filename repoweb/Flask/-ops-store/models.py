import os

from flask import Flask
from flask_sqlalchemy import SQLAlchemy

# Databse Path
dbdir = "sqlite:///" + os.path.abspath(os.getcwd()) + "/databases/store.db"

# Configure application
app = Flask(__name__)

# Configure the SQLite database, relative to the app instance folder
app.config["SQLALCHEMY_DATABASE_URI"] = dbdir

# Create the extension
db = SQLAlchemy(app)

# Class Model
# A class is created and we create a connection instance into it
class Role(db.Model):
  __tablename__="roles"
  id=db.Column(db.Integer, primary_key=True)
  name=db.Column(db.String(5), unique=True)
  users=db.relationship("User", backref="role")

  def __repr__(self):
      return"<Role %r>" %self.name

class User(db.Model):
  __tablename__="users"
  id=db.Column(db.Integer, primary_key=True)
  username=db.Column(db.String(50), unique=True, index=True)
  hash = db.Column(db.String(80),  nullable=False)
  role_id=db.Column(db.Integer, db.ForeignKey("roles.id"))

  def __repr__(self):
      return"<User %r>" %self.username

