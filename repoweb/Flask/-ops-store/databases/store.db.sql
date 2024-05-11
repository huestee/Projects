BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS "roles" (
	"id"	INTEGER NOT NULL,
	"name"	VARCHAR(5) NOT NULL,
	UNIQUE("name"),
	PRIMARY KEY("id")
);
CREATE TABLE IF NOT EXISTS "users" (
	"id"	INTEGER NOT NULL,
	"username"	VARCHAR(50) NOT NULL,
	"hash"	VARCHAR(80) NOT NULL,
	"role_id"	INTEGER NOT NULL,
	FOREIGN KEY("role_id") REFERENCES "roles"("id"),
	PRIMARY KEY("id")
);
CREATE TABLE IF NOT EXISTS "products" (
	"id"	INTEGER NOT NULL,
	"name"	VARCHAR(60) NOT NULL,
	"description"	VARCHAR(200) NOT NULL,
	"price"	INTEGER NOT NULL,
	"quantity"	FLOAT NOT NULL,
	PRIMARY KEY("id")
);
INSERT INTO "roles" ("id","name") VALUES (1,'admin');
INSERT INTO "roles" ("id","name") VALUES (2,'user');
INSERT INTO "users" ("id","username","hash","role_id") VALUES (1,'asd','pbkdf2:sha256:260000$lVbh6ArpZPZEAQSQ$a8a167f783edb502b86f1269f1ea9f873dac89886aaa9e1ca1b7635ca30b6a9d',2);
INSERT INTO "users" ("id","username","hash","role_id") VALUES (2,'qwe','pbkdf2:sha256:260000$KbG56SIpqmgR2hpq$6a2bee92ba4a1bbb7da192c29a4d02880089bbbeedb67ad1087423ca328170ea',1);
CREATE UNIQUE INDEX IF NOT EXISTS "ix_users_username" ON "users" (
	"username"
);
CREATE UNIQUE INDEX IF NOT EXISTS "ix_products_name" ON "products" (
	"name"
);
COMMIT;
