```
███████╗████████╗     ██████╗ ██████╗ ██╗███╗   ██╗████████╗███████╗
██╔════╝╚══██╔══╝     ██╔══██╗██╔══██╗██║████╗  ██║╚══██╔══╝██╔════╝
█████╗     ██║        ██████╔╝██████╔╝██║██╔██╗ ██║   ██║   █████╗  
██╔══╝     ██║        ██╔═══╝ ██╔══██╗██║██║╚██╗██║   ██║   ██╔══╝  
██║        ██║███████╗██║     ██║  ██║██║██║ ╚████║   ██║   ██║     
╚═╝        ╚═╝╚══════╝╚═╝     ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝   ╚═╝     
```

This is a replication of the printf function with some basic flags, made according with the 42's subject pdf.
It fully implements the mandatory part with support for `%sdiupxXc` flags, and the bonus flags `#0. +-`.

It works by parsing all the flags and storing all the info in a big struct. After that, we call the function according with the flag passed and use the information from our struct to manipulate the string. (Check ft_parse_special_bonus.c)

This code was graded with the maximum score of 125/100 by Moulinette.

<img width="1280" height="422" alt="Screenshot from 2025-08-13 19-00-14" src="https://github.com/user-attachments/assets/7c9c482d-5ff7-4e35-93cd-08be37e40c28" />

## Compiling

To compile the mandatory function:
```bash
make all
```

To compile the bonus function:
```bash
make bonus
```
