import os
import requests
import json

class Colors:
    HEADER = '\033[95m'
    BLUE = '\033[94m'
    GREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

def filter_projects_by_pool_year(projects_users, target_year="2023"):
    filtered_entries = [
        entry for entry in projects_users 
        if entry.get('user', {}).get('pool_year') == target_year
    ]
    return filtered_entries

os.system('clear')

campus_filter = print("Choose your campus: ")
print("1: Khouribga")
print("2: Benguerir")
print("3: TÃ©touan")
compus_code = input("\n> ")
if (compus_code == "1"):
    campus_filter = 16
elif (compus_code == "2"):
    campus_filter = 21
elif (compus_code == "3"):
    campus_filter = 55
else:
    print("wrong input")
    exit()

os.system('clear')

print(Colors.HEADER + "----------- Libft Speedrunners Finder -----------\n" + Colors.ENDC)
print(Colors.WARNING + "> Looking for Libft speedrunners...\n" + Colors.ENDC)

UID = "u-s4t2ud-34afa50237a667d447cd7e2146b54f948e923ef927257122ce9ff34e0c267217"
SECRET = "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"
BASE_API = "https://api.intra.42.fr/"

token_url = f"{BASE_API}oauth/token"
token_data = {
    'grant_type': 'client_credentials',
    'client_id': UID,
    'client_secret': SECRET,
}
token_r = requests.post(token_url, data=token_data)
token = token_r.json().get('access_token')

endpoint = f"/v2/projects/42cursus-libft/projects_users"

params = {
    'filter[campus]': campus_filter,
    'filter[status]': "waiting_for_correction"
}

headers = {
    'Authorization': f'Bearer {token}',
}
response = requests.get(f"{BASE_API}{endpoint}", headers=headers, params=params)

if response.status_code == 200:
    projects_users = response.json()
    filtered_data = filter_projects_by_pool_year(projects_users)

    if len(filtered_data) == 0:
        print(Colors.GREEN + "> No MFs found! Good, study hard students.\n" + Colors.ENDC)
        exit()
    
    print(Colors.WARNING + "> Students waiting for their death:" + Colors.ENDC)
    for entry in filtered_data:
        user_info = entry.get('user', {})
        login = user_info.get('login', 'N/A')
        full_name = user_info.get('usual_full_name', 'N/A')
        intra_link = f"https://profile.intra.42.fr/users/{login}"

        print(Colors.BLUE + f"- Login:" + Colors.ENDC + f" {login}")
        print(Colors.BLUE + f"- Full name:" + Colors.ENDC + f" {full_name}")
        print(Colors.BLUE + f"- Intra Link:" + Colors.ENDC + f" {intra_link}")
        print("----------------------------------------")

else:
    print(Colors.FAIL + f"Error: Unable to fetch data (Status code: {response.status_code})")
    print(response.text + Colors.ENDC)