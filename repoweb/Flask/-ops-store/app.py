import os

from flask import Flask, render_template, request, redirect, flash, session, url_for
from flask_session import Session
from flask_sqlalchemy import SQLAlchemy

from werkzeug.security import generate_password_hash, check_password_hash
from werkzeug.utils import secure_filename

from helpers import login_required, role_required, usd
# from models import Role, User

# Databse Path
dbdir = "sqlite:///" + os.path.abspath(os.getcwd()) + "/databases/store.db"

# Configure application
app = Flask(__name__)

# Configure the SQLite database, relative to the app instance folder
app.config["SQLALCHEMY_DATABASE_URI"] = dbdir

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True
""" app.config['SECRET_KEY'] = '5791628bb0b13ce0c676dfde280ba245' """
app.config["SQLALCHEMY_TRACK_MODIFICATIONS"] = False

# Create the extension
db = SQLAlchemy(app)

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)


# Class Model
# A class is created and we create a connection instance into it
class Role(db.Model):
  __tablename__="roles"
  id=db.Column(db.Integer, primary_key=True)
  name=db.Column(db.String(5), unique=True, nullable=False)
  users=db.relationship("User", backref="role")

  def __repr__(self):
      return"<Role %r>" %self.name

class User(db.Model):
  __tablename__="users"
  id=db.Column(db.Integer, primary_key=True)
  username=db.Column(db.String(50), unique=True, index=True, nullable=False)
  hash = db.Column(db.String(80),  nullable=False)
  cash=db.Column(db.Float, nullable=False)
  role_id=db.Column(db.Integer, db.ForeignKey("roles.id"), nullable=False)
  users=db.relationship("Transaction", backref="user")

  def __repr__(self):
    return"<User %r>" %self.username

class Upload(db.Model):
  __tablename__="uploads"
  id=db.Column(db.Integer, primary_key=True)
  name=db.Column(db.Text, unique=True, nullable=False)
  data=db.Column(db.LargeBinary, nullable=False)
  mimetype=db.Column(db.Text, nullable=False)
  product=db.relationship("Product", backref="Upload")
  product=db.relationship("Transaction", backref="Upload")
  
  def __repr__(self):
    return"<User %r>" %self.name

class Product(db.Model):
  __tablename__="products"
  id=db.Column(db.Integer, primary_key=True)
  name=db.Column(db.String(60), unique=True, index=True, nullable=False)
  um=db.Column(db.String(10), nullable=False)
  description=db.Column(db.String(200), nullable=False)
  price=db.Column(db.Float, nullable=False)
  quantity=db.Column(db.Integer, nullable=False)
  #img=db.Column(db.String(250), nullable=False)
  upload_id=db.Column(db.Integer, db.ForeignKey("uploads.id"), nullable=False)

  def __repr__(self):
    return "<Product %r>" %self.name


class Transaction(db.Model):
  __tablename__="transactions"
  id=db.Column(db.Integer, primary_key=True)
  name=db.Column(db.String(60), index=True, nullable=False)
  price=db.Column(db.Float, nullable=False)
  amount=db.Column(db.Float, nullable=False)
  user_id=db.Column(db.Integer, db.ForeignKey("users.id"), nullable=False)
  upload_id=db.Column(db.Integer, db.ForeignKey("uploads.id"), nullable=False)

  def __repr__(self):
    return "<Product %r>" %self.name



 

""" ----------------Indexclear---------------- """
@app.route("/")
@login_required
def index():
  # Current User
  user_id = session["user_id"]
  # Query database
  product = Product.query.all()
  upload = Upload.query.all()
  # print(type(symbols))
  # Stocks with any shares. All were sold

  imgs = []
  for row in upload:
    imgs.append(row)

    # print(name)
    # return jsonify(name)
  return render_template("/index.html", products=product, imgs=imgs)
  

""" ------------------Log In------------------ """
@app.route("/login", methods=["GET", "POST"])
def login():
  """Log user in"""

  # Forget any user_id
  session.clear()

  # User reached route via POST (as by submitting a form via POST)
  if request.method == "POST":
    
    username = request.form.get("username")
    password = request.form.get("password")

    # Ensure username was submitted
    if not username:
      flash('Must provide username')
      return render_template("/login.html")

    # Ensure password was submitted
    elif not password:
      flash('Must provide password')
      return render_template("/login.html")

    # Query database for username
    user = User.query.filter_by(username=username).first()

    """ user = []
    for i in current_user:
      user.append(i) """
    db.session.commit()

    #rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

    # Ensure username exists and password is correct
    if not user or not check_password_hash(user.hash, password):
      flash('Try Again, invalid username and/or password.')
      return render_template("/login.html")

    # Remember which user has logged in
    session["user_id"] = user

    # Remember which role user
    role = Role.query.filter(Role.id==1).first()

    current_rol = user.query.filter(user.role_id == role.id).count()

    #session["current_user_role_id"] = current_rol

    session["current_user_role_id"] = None

    if user.role_id == role.id:
      session["current_user_role_id"] = current_rol


    # Redirect user to home page
    return redirect("/")

  # User reached route via GET (as by clicking a link or via redirect)
  else:
    return render_template("/login.html")


""" -----------------Log Out----------------- """
@app.route("/logout")
def logout():
  """Log user out"""

  # Forget any user_id
  session.clear()

  # Redirect user to login form
  return redirect("/")


""" --------------Register User-------------- """
@app.route("/register", methods=["GET", "POST"])
def register():
  """ Register User """
  if request.method == "POST":
    username = request.form.get("username")
    rols = request.form.get("role")
    password = request.form.get("password")
    confirmation = request.form.get("confirmation")

    # Ensure username was submitted
    if not username:
      flash('Must provide username')
      return render_template("/register.html")

    # Ensure role was selected
    elif not rols:
      flash('Must choose a role')
      return render_template("/register.html")

    # Ensure password was submitted
    elif not password:
      flash('Must provide password')
      return render_template("/register.html")
    
    # Ensure confirmation password do not match
    elif password != confirmation:
      flash('Password do not match')
      return render_template("/register.html")
      """ # Ensure username already exist
      elif len(rows) != 0:
      return apology("Invalid username already exist", 403) """
    else:
      # Secure password with hash,
      hash = generate_password_hash(password)
      
      #db.session.commit()
      #role=role

      try:
        # Get Rol ID
        role = Role.query.filter_by(name=rols).first()
        
        # Class Instance
        new_user = User(username=username, hash=hash, cash=usd(10000), role_id=role.id)
        # Save into database
        db.session.add(new_user)
        db.session.commit()

        flash('Registrated Successfully')
      except:
        # Ensure username already exist
        flash('Username already exists')
        return render_template("/register.html")

      # Remember which user has logged in
      session["user_id"] = new_user

    # Remember which role user
    role = Role.query.filter(Role.id==1).first()

    #current_rol = role
    current_rol = new_user.query.filter(new_user.role_id == role.id).count()
    
    session["current_user_role_id"] = None

    if new_user.role_id == role.id:
      session["current_user_role_id"] = current_rol

    # Redirect user to home page
    return redirect("/")

  # User reached route via GET (as by clicking a link or via redirect)
  else:
    return render_template("/register.html")


""" ---------Extension IMG------------ """
ALLOWED_EXTENSIONS = {'txt', 'pdf', 'png', 'jpg', 'jpeg', 'gif'}
def allowed_file(filename):
  return '.' in filename and \
    filename.rsplit('.', 1)[1].lower() in ALLOWED_EXTENSIONS


""" -----------------Add Product----------------- """
@app.route("/addproduct", methods=["GET", "POST"])
@login_required
@role_required
def addproduct():
  """User Admin can add product"""
  # Current User
  user_id = session["user_id"]

  if request.method == "POST":
    pname = request.form.get("name").upper()
    pum = request.form.get("um").upper()
    pdescription = request.form.get("description").upper()
    pprice = request.form.get("price")
    pquantity = request.form.get("quantity")
    #pimg = request.form.get("image")
    pimg = request.files['image']
    
    # Ensure name was submitted
    if not pname:
      flash('Must provide product name')
      return render_template("/addproduct.html")

    # Ensure unit of measurement was submitted
    if not pum:
      flash('Must provide unit of measurement')
      return render_template("/addproduct.html")

    # Ensure description was submitted
    elif not pdescription:
      flash('Must provide a little product description')
      return render_template("/addproduct.html")

    # Ensure price was submitted
    elif not pprice:
      flash('Must provide product price')
      return render_template("/addproduct.html")

    # Ensure quantiity was submitted
    elif not pquantity:
      flash('Must provide product quantity')
      return render_template("/addproduct.html")
    
    # Ensure image was submitted
    elif not pimg:
      flash('Must provide product image')
      return render_template("/addproduct.html")

    elif pimg.filename == '':
      flash('No seleted image')
      return render_template("/addproduct.html")
    
    elif not (pimg and allowed_file(pimg.filename)):
      flash('Format no supported')
      return render_template("/add.html")

    else:
      pprice = float(pprice)
      pquantity = int(pquantity)
      # Add product image
      filename = secure_filename(pimg.filename)
      path = f'static\img\{filename}' 
      #app.root_path
      mimetype = pimg.mimetype
      pimg.save(path)

      img = Upload(name=path, data=pimg.read(), mimetype=mimetype)
      # Save into database
      db.session.add(img)
      db.session.commit()

      try:
        # Get Image ID
        #current_img = img.query.filter_by(name=path)

        # Add product
        new_product = Product(name=pname, um=pum, description=pdescription, price=usd(pprice), quantity=pquantity, upload_id=img.id)

        # Save into database
        db.session.add(new_product)
        db.session.commit()

        flash('Product added succesfully')
      except Exception as e:
        flash('Product already exists')
        #flash(e)
        return render_template("/addproduct.html")

      product = Product.query.all()
      upload = Upload.query.all()
      # print(type(symbols))
      # Stocks with any shares. All were sold

      imgs = []
      for row in upload:
        imgs.append(row)

    return render_template("/index.html", products=product, imgs=imgs)
  else:
    return render_template("/addproduct.html")


"""------------------Index Products------------------ """
@app.route("/product")
@login_required
def product():
  # Current User
  user_id = session["user_id"]
  # Query database
  transaction = Transaction.query.filter_by(user_id=user_id.id).all()
  cash = User.query.filter_by(id=user_id.id).first()
  upload = Upload.query.all()

  imgs = []
  for row in upload:
    imgs.append(row)

    # print(name)
    # return jsonify(name)
  return render_template("/product.html", transactions=transaction, imgs=imgs, cash=cash.cash)


""" -----------Pass Name Product To Buy Page Input Field------------- """
""" @app.route("/action", methods=["GET", "POST"])
@login_required
def action():
  if request.method == "GET":
    request.form
    name = request.form.get("") """


""" -----------Buy Product------------- """
@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
  """Buy shares of stock"""
  # Current User
  user_id = session["user_id"]
  if request.method == "POST":
    pname = request.form.get("name").upper()
    pquantity = request.form.get("quantity")

    #product = Product.query.all()
    
    # Ensure name was submitted
    if not pname:
      flash('Must provide product name')
      return render_template("/buy.html")

    # Ensure unit of measurement was submitted
    if not pquantity:
      flash('Must provide quantity of the product')
      return render_template("/buy.html")

    # Current Product to buy
    product_db = Product.query.filter_by(name=pname).first()

    # Ensure username exists and password is correct
    if not product_db:
      flash('Try Again, invalid product name.')
      return render_template("/buy.html")

    if product_db.quantity == 0:
      flash('Sorry, Product is currently unavailable.')
      return render_template("/buy.html")

    # Quantity of the product
    pquantity = int(pquantity)
    
    # Ensure shares is positive int
    if pquantity < 1:
      flash('It have to be one at least')
      return render_template("/buy.html")
    if pquantity > product_db.quantity:
      flash('Enough product quantity to offer you. Change it please.')
      return render_template("/buy.html")

    # Current User
    user = User.query.filter_by(id=user_id.id).first()
    
    # Current Cash User
    cash = float(user.cash)

    # Operations
    price = float(product_db.price)
    amount = float(pquantity*price)

    # Make sure user has enough money for the purchase
    if amount > cash:
      flash('Sorry do not have enough money')
      return render_template("/buy.html")
    else:
      upcash = float(cash - amount)
      upquantity = int(product_db.quantity - pquantity)

      # Updating cash field
      User.query.filter(User.id==user_id.id).update({User.cash:usd(upcash)})
      Product.query.filter(Product.id==product_db.id).update({Product.quantity:upquantity})
      db.session.commit()

      buy = Transaction(name=pname, price=price, amount=amount, user_id=user_id.id, upload_id=product_db.upload_id)
      db.session.add(buy)
      db.session.commit()

      trans = Transaction.query.filter_by(user_id=user_id.id).all()
      upload = Upload.query.all()

      imgs = []
      for row in upload:
        imgs.append(row)

      return render_template("/product.html", transactions=trans, imgs=imgs, cash=upcash)

  else:
    return render_template("/buy.html")

if __name__ == "__main__":
  with app.app_context():
    db.create_all()
  
  # Run App
  app.run(host='0.0.0.0', port=5000, debug=True)