from bar import hello

if __name__ == "__main__":
    hello()
    #bar.main()
    print("Hey from foo")
    print(f"Global namespace: {globals()}")
