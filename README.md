# Simple Contacts App

A small command-line telephone directory written in C. Contacts are stored in a local text file so you can add, search, and delete entries without a database.

## Features

- **Add contact** — save name, phone number, and email
- **Delete contact** — remove a contact by name (rewrites the file via a temp file)
- **Search contact** — find contacts by partial name match and print full details

## Requirements

- A C compiler (`gcc` recommended)
- Standard C library (`stdio.h`, `string.h`)

Works on Windows, Linux, and macOS.

You will see a menu:

Action,    How it works
Add,       Appends name|phone|email to contacts.txt
Delete,    "Matches by name, copies other lines to temp.txt, then replaces contacts.txt"
Search,    "Partial match on name (strstr); prints name, phone, and email"

## ATTENTION

For delete and search, the name field is what matters. Phone and email are still requested by the shared input function.
