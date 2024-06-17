import os
import subprocess
from datetime import datetime
from urllib.parse import quote

# Function to parse comment lines and extract question details
def parse_comments(lines):
    fieldnames = ["Date", "Start Time", "End Time", "Time Taken", "QUESTION LINK", "Code Link", "Rating", "Description", "Solved", "Learning"]
    details = {}
    for line in lines:
        line = line.strip()
        if line.startswith("//"):
            # Ensure the line contains a colon
            if ':' in line[2:]:
                key_value = line[2:].strip().split(':', 1)
                if len(key_value) == 2:
                    key = key_value[0].strip()
                    if key in fieldnames:
                        value = key_value[1].strip()
                        details[key] = value
    return details

# Function to update Markdown file with question details
def update_markdown(details):
    # Create filename based on the current month and year
    now = datetime.now()
    folder_name = "HISTORY"
    file_name = now.strftime("%Y-%m") + ".md"
    md_file = os.path.join(folder_name, file_name)

    # Ensure the HISTORY folder exists
    if not os.path.exists(folder_name):
        os.makedirs(folder_name)

    # Check if Markdown file exists
    is_empty = not os.path.exists(md_file) or os.stat(md_file).st_size == 0

    # Update or append data
    with open(md_file, 'a') as f:
        if is_empty:
            # Write header only if the file is empty
            f.write("| Date | Start Time | End Time | Time Taken | QUESTION LINK | Code Link | Rating | Description | Solved | Learning |\n")
            f.write("|------|-------------|----------|------------|----------------|-----------|--------|-------------|--------|-----------|\n")
        # Write the details
        row = "| " + " | ".join([details.get(field, "") for field in ["Date", "Start Time", "End Time", "Time Taken", "QUESTION LINK", "Code Link", "Rating", "Description", "Solved", "Learning"]]) + " |\n"
        f.write(row)

# Function to get untracked .cpp files using Git and sort them by file creation time
def get_untracked_cpp_files():
    untracked_files = subprocess.check_output(["git", "ls-files","--modified", "--others", "--exclude-standard", ":!main.cpp", "--", "*.cpp"]).decode().splitlines()
    # Sort untracked files based on file creation time
    untracked_files.sort(key=lambda x: os.path.getctime(x))
    return untracked_files

# Function to generate GitHub link for a given file path
def generate_github_link(file_path):
    base_url = "https://github.com/ENAMINE1/CP-JOURNEY/tree/main/"
    relative_path = os.path.relpath(file_path)
    encoded_path = quote(relative_path.replace("\\", "/"))
    github_link = base_url + encoded_path
    return github_link

# Main function to update Markdown with untracked .cpp files
def main():
    untracked_files = get_untracked_cpp_files()
    if untracked_files:
        for file in untracked_files:
            with open(file, 'r') as f:
                lines = f.readlines()
                details = parse_comments(lines)
                if details.get("QUESTION LINK"):
                    alias = os.path.basename(file)  # Use just the file name as the alias
                    full_link = generate_github_link(file)
                    details["Code Link"] = f"[{alias}]({full_link})"  # Use Markdown format
                    update_markdown(details)
                    print(f"Added details for {file} to Markdown file.")
    else:
        print("No untracked .cpp files found.")

if __name__ == "__main__":
    main()
