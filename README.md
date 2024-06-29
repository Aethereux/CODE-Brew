# README: How to Use GitHub and Collaborate on My Project

## Table of Contents
1. [Introduction](#introduction)
2. [Getting Started](#getting-started)
   - [Prerequisites](#prerequisites)
   - [Setup](#setup)
3. [Using GitHub](#using-github)
   - [Creating a Repository](#creating-a-repository)
   - [Cloning the Repository](#cloning-the-repository)
   - [Making Changes](#making-changes)
   - [Committing Changes](#committing-changes)
   - [Pushing Changes](#pushing-changes)
4. [Collaborating on the Project](#collaborating-on-the-project)
   - [Forking the Repository](#forking-the-repository)
   - [Creating a Branch](#creating-a-branch)
   - [Making Pull Requests](#making-pull-requests)
   - [Reviewing and Merging Pull Requests](#reviewing-and-merging-pull-requests)

## Introduction
This README file provides a step-by-step guide on how to use GitHub for version control and collaboration on your project. Whether you are new to GitHub or need a refresher, this guide will help you get started and work effectively with others.

## Getting Started

### Prerequisites
- A GitHub account. Sign up at [GitHub](https://github.com/) if you don’t have one.
- Git installed on your local machine. Download and install it from [here](https://git-scm.com/downloads).

### Setup
1. **Create a GitHub account**: Go to [GitHub](https://github.com/) and sign up for an account.
2. **Install Git**: Follow the instructions to install Git on your computer from [here](https://git-scm.com/downloads).
3. **Set up Git**:
   ```sh
   git config --global user.name "Your Name"
   git config --global user.email "your-email@example.com"
   ```

## Using GitHub

### Creating a Repository
1. Go to [GitHub](https://github.com/) and log in.
2. Click the "+" icon in the top right corner and select "New repository".
3. Enter a repository name, description, and select "Public" or "Private".
4. Click "Create repository".

### Cloning the Repository
1. On your repository page, click the "Code" button and copy the URL.
2. Open a terminal on your local machine and run:
   ```sh
   git clone https://github.com/Aethereux/CODE-Brew
   ```
3. Navigate to the repository directory:
   ```sh
   cd your-repository
   ```

### Making Changes
1. Open the project files in your favorite code editor.
2. Make the necessary changes to the files.

### Committing Changes
1. Add the changes to the staging area:
   ```sh
   git add .
   ```
2. Commit the changes with a message:
   ```sh
   git commit -m "Your commit message"
   ```

### Pushing Changes
1. Push the changes to GitHub:
   ```sh
   git push origin main
   ```

## Collaborating on the Project

### Forking the Repository
1. Go to the repository page on GitHub.
2. Click the "Fork" button in the top right corner.

### Creating a Branch
1. Clone your forked repository:
   ```sh
   git clone https://github.com/Aethereux/CODE-Brew
   ```
2. Navigate to the repository directory:
   ```sh
   cd your-forked-repository
   ```
3. Create a new branch:
   ```sh
   git checkout -b your-branch-name
   ```

### Making Pull Requests
1. Push your branch to your forked repository:
   ```sh
   git push origin your-branch-name
   ```
2. Go to your forked repository on GitHub.
3. Click the "Compare & pull request" button.
4. Provide a title and description for your pull request.
5. Click "Create pull request".

### Reviewing and Merging Pull Requests
1. Go to the original repository on GitHub.
2. Click on "Pull requests" and select the one you want to review.
3. Review the changes and add comments if necessary.
4. If the changes are acceptable, click "Merge pull request".
5. Delete the branch after merging.
