# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    build.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmichele <mmichele@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: Invalid date        by o PDF using       #+#    #+#              #
#    Updated: 2025/11/08 00:59:24 by mmichele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Function that compiles a given LaTeX file passed as an argument
compile() {
    dir_path=$(dirname "$1")        # Extract the directory path
    if [ -d "class" ]; then         # Checks if class directory exists
        mv "class"/* "$dir_path"/   # Move all files from template directory to the file path
    fi
    cd "$dir_path"                  # Change directory to the file path
    mkdir -p "build"                # Create build directory if it doesn't exists
    file=$(basename "$path")        # Filename
    # Moving all files from build directory with same basename
    find "build" -maxdepth 1 -type f -name "$(basename "$file" .tex).*" -exec mv -t . {} +
    # Compile LaTex files to PDF using pdflatex, not stopping on errors and redirecting output to /dev/null
    echo "Compiling $path"
    # Compiling twice to ensure the creation of table of contents
    pdflatex -interaction=nonstopmode "$file" > /dev/null 2>&1
    pdflatex -interaction=nonstopmode "$file" > /dev/null 2>&1
    # Moving all files with same basename except .tex, .pdf, .cls, and .sty files to build directory
    find . -maxdepth 1 -type f \( -name "$(basename "$file" .tex).*" ! -name "*.pdf" ! -name "*.tex" ! -name "*.cls" ! -name "*.sty" \) -exec mv -t build {} +
    cd "$root"
    # Move all .cls and .sty files back to class directory
    if [ -d "class" ]; then
        mv "$dir_path"/*.cls "class"/
        mv "$dir_path"/*.sty "class"/
    fi
}

# Searches for all latex files if no arguments are passed
if [ $# -eq 0 ]; then
    files=$(find . -type f -name "*.tex")
else
    # TODO Check if file passed as argument exists
    files=$@
fi

root=$(pwd)
# Loop through each file path
for path in $files; do
    compile "$path"
done