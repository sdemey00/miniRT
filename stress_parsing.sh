RED='\033[1;31m'
GREEN='\033[1;32m'
BLUE='\033[1;34m'
CYAN='\033[1;36m'
RESET='\033[0m'

for f in ./static/*.rt; do
    echo -e "\n${CYAN}============================================${RESET}"
    echo -e "${BLUE}Testing file: $f${RESET}\n"
    echo -e "${GREEN}--- Map content ---${RESET}"
    cat "$f"
    echo -e "${GREEN}\n--- End of map ---${RESET}\n"
    echo -e "${CYAN}--- miniRT Output ---${RESET}"
    ./miniRT "$f"
    echo -e "${CYAN}--- End of Output ---${RESET}"
    echo -e "${CYAN}============================================${RESET}\n"
done
