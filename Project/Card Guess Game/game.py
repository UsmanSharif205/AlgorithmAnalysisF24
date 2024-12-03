import tkinter as tk
import random
from tkinter import messagebox

# Sample food items
FOODS = ["Pizza", "Burger", "Sushi", "Taco", "Pasta", "Donut", "Salad", "Steak"]

class MemoryGame:
    def __init__(self, root):
        self.root = root
        self.root.title("Food Matching Game")

        # Duplicate and shuffle the food items
        self.cards = FOODS * 2
        random.shuffle(self.cards)

        self.buttons = []
        self.first_card = None
        self.second_card = None
        self.matches_found = 0

        # Create buttons for the cards
        for i, card in enumerate(self.cards):
            button = tk.Button(root, text="", width=10, height=5, 
                               bg="lightblue",
                               command=lambda i=i: self.flip_card(i))
            button.grid(row=i // 4, column=i % 4)
            self.buttons.append(button)

    def flip_card(self, index):
        if self.first_card is not None and self.second_card is not None:
            return  # Wait for mismatched cards to reset

        button = self.buttons[index]

        # Reveal card if not already matched
        if not button.cget("state") == "disabled":
            button.config(text=self.cards[index], state="disabled")

            if self.first_card is None:
                self.first_card = index
            elif self.second_card is None:
                self.second_card = index

                # Check for a match
                self.root.after(1000, self.check_match)

    def check_match(self):
        first_idx, second_idx = self.first_card, self.second_card

        if self.cards[first_idx] == self.cards[second_idx]:
            self.matches_found += 1
            self.buttons[first_idx].config(bg="lightgreen")
            self.buttons[second_idx].config(bg="lightgreen")
        else:
            self.buttons[first_idx].config(text="", state="normal", bg="lightblue")
            self.buttons[second_idx].config(text="", state="normal", bg="lightblue")

        # Reset selections
        self.first_card = None
        self.second_card = None

        # Check if the game is over
        if self.matches_found == len(FOODS):
            messagebox.showinfo("Congratulations!", "You've matched all the cards!")
            self.root.quit()

if __name__ == "__main__":
    root = tk.Tk()
    game = MemoryGame(root)
    root.mainloop()
