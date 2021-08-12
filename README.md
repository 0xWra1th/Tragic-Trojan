THIS PROJECT IS FOR EDUCATIONAL PURPOSES ONLY! DO NOT USE THIS CODE MALICIOUSLY.
<br/>
<p align="center">
  <a href="https://github.com/github_username/repo_name">
    <img src="https://enterprise.comodo.com/images/what-is-the-trojan-horse-virus.webp" alt="Logo" width="200" height="200">
  </a>
  <h3 align="center">Tragic Trojan</h3>
</p>
<br/>
In computing, a Trojan horse is any malware which misleads users of its true intent.

That presents the question, what is the true intent?

### The true intent

Pwnage. Total domination of a system.
But realistically the goal of this project is learning the basics of malware development.

### Target and Goal

Windows users are the target and I will attempt to create a backdoor for remote code execution.

### The components

   * A useful application? Or maybe not so useful...A game?
      * Pygame will help to achieve this.
   * The backdoor.
      * Sockets.
      * Going to need some form of AV evasion.

### Problems encountered

   * Cross-platform socket programming in C++ seems to be difficult.
   * Packaging C++ and a Pygame together
   * AV Evasion
   * Need to learn the Windows API

### What have I learned so far
  1. You need a target and goal. (e.g. Target windows users to add them to a botnet or steal passwords)

### Timeline

  1. Create Pygame frontend
  2. Create Python payload
  3. Discover C++ is better for malware development and AV evasion
  4. Create C++ payload
  5. Struggle to package python and C++ together
  6. Create a frontend in C++, maybe not a game...
