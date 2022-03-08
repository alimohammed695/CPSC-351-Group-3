# Contributing Guidelines

We'll keep it simple and just work in separate feature branches. Once a feature is done, submit a pull request to merge into `master`.
Also, here's a guide for creating good [commit messages](https://chris.beams.io/posts/git-commit/).

## Setting up your dev environment

If you ever get lost, follow Github's [Fork a repo](https://docs.github.com/en/free-pro-team@latest/github/getting-started-with-github/fork-a-repo) guide.

We'll also be using [Git](https://git-scm.com/downloads) so make sure you have it installed.

### Clone the repo

First click the "fork" button to create your own copy of the project.

Then use ssh

```bash
git clone git@github.com:your-username/CPSC-351-Group-3.git
```

Or https

```bash
git clone https://github.com/your-username/CPSC-351-Group-3.git
```

Change to the CPSC-351-Group-3 directory

```bash
cd CPSC-351-Group-3
```

Add the upstream repository

```bash
git remote add upstream https://github.com/AnOrdinaryUsername/CPSC-351-Group-3.git
```

### Develop your contribution

Pull the latest changes from upstream

```bash
git checkout master
git pull upstream master
```

Create a branch for feature you want to work on

```bash
git checkout -b branch-feature-name
```

Commit any changes as you make the feature. Remember to use this helpful [guide](https://chris.beams.io/posts/git-commit/).

```bash
git add file-name.cpp
git commit -m "Meaningful message here"
```

### Submit your contribution

Push changes to your fork

```bash
git push origin your-branch-feature-name
```

Now click the green pull request button, add your title and message, and submit your changes!