import tkinter as tk
from tkinter import messagebox

class TicTacToe:
    def __init__(self):
        self.window = tk.Tk()
        self.window.title("Tic Tac Toe")
        self.current_player = "X"  # Player "X" starts the game
        self.board = [["" for _ in range(3)] for _ in range(3)]  # 3x3 board
        self.buttons = [[None for _ in range(3)] for _ in range(3)]  # Button grid

        # Create the grid of buttons
        for row in range(3):
            for col in range(3):
                self.buttons[row][col] = tk.Button(
                    self.window, text="", font=("Arial", 24), width=5, height=2,
                    command=lambda r=row, c=col: self.on_click(r, c)
                )
                self.buttons[row][col].grid(row=row, column=col)

    def on_click(self, row, col):
        # Check if the cell is empty
        if self.board[row][col] == "":
            self.board[row][col] = self.current_player
            self.buttons[row][col].config(text=self.current_player)

            # Check for a win or a tie
            if self.check_winner(self.current_player):
                self.show_winner(self.current_player)
            elif self.is_tie():
                self.show_tie()
            else:
                # Switch players
                self.current_player = "O" if self.current_player == "X" else "X"

    def check_winner(self, player):
        # Check rows, columns, and diagonals for a win
        for i in range(3):
            if all(self.board[i][j] == player for j in range(3)):  # Check rows
                return True
            if all(self.board[j][i] == player for j in range(3)):  # Check columns
                return True
        # Check diagonals
        if all(self.board[i][i] == player for i in range(3)):
            return True
        if all(self.board[i][2 - i] == player for i in range(3)):
            return True
        return False

    def is_tie(self):
        # Check if the board is full
        for row in self.board:
            if "" in row:
                return False
        return True

    def show_winner(self, player):
        messagebox.showinfo("Tic Tac Toe", f"Player {player} wins!")
        self.reset_game()

    def show_tie(self):
        messagebox.showinfo("Tic Tac Toe", "It's a tie!")
        self.reset_game()

    def reset_game(self):
        # Reset the board and buttons for a new game
        self.board = [["" for _ in range(3)] for _ in range(3)]
        for row in range(3):
            for col in range(3):
                self.buttons[row][col].config(text="")
        self.current_player = "X"

    def run(self):
        self.window.mainloop()

# Run the game
if __name__ == "__main__":
    game = TicTacToe()
    game.run()
