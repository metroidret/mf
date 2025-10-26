import argparse
from io import BufferedReader
import json
from pathlib import Path


DATA_PATH = "data/"
DATABASE_PATH = "database.json"
DATABASE_DEBUG_PATH = "database_debug.json"


def extract_data(region: str, debug: bool, quiet: bool = False) -> None:
    if debug:
        region = "eu_beta"
    rom: BufferedReader = open(f"mf_{region}_baserom.gba", "rb")
    db_path = DATABASE_DEBUG_PATH if debug else DATABASE_PATH
    with open(db_path, "r") as f:
        db = json.load(f)

    for entry in db:
        path: str = entry["path"]
        if not quiet:
            print(f"Extracting {path}")

        # Create directories if they don't exist
        path_obj = Path(DATA_PATH + path)
        path_obj.parent.mkdir(parents=True, exist_ok=True)

        addr = entry["addr"].get(region)
        if addr is not None:
            count = entry["count"]
            if isinstance(count, dict):
                count = count[region]
            size: int = int(count, 16) * entry["size"]
            rom.seek(int(addr, 16))
            with open(path_obj, "wb") as f:
                f.write(rom.read(size))

    rom.close()


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    group = parser.add_mutually_exclusive_group()
    # TODO: Add "eu", "jp", "cn", "eu_beta"
    group.add_argument("-r", "--region", type=str, choices=["us"],
        default="us", help="The region of the rom to extract from")
    # TODO: Support debug
    # group.add_argument("-d", "--debug", action="store_true",
    #     help="Extract debug data from the EU beta rom")
    parser.add_argument("-q", "--quiet", action="store_true", help="Suppress output")
    
    args = parser.parse_args()
    # TODO: Remove this line
    args.debug = False
    if not args.region and not args.debug:
        args.region = "us"

    extract_data(args.region, args.debug, args.quiet)
