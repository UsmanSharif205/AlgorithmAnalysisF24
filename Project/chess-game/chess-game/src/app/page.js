"use client";
import React, { useEffect, useRef, useState } from "react";
import "./page.css";
// import click from "../../public/click.mp3";

const initialBoard = [
  ["r", "n", "b", "q", "k", "b", "n", "r"],
  ["p", "p", "p", "p", "p", "p", "p", "p"],
  [".", ".", ".", ".", ".", ".", ".", "."],
  [".", ".", ".", ".", ".", ".", ".", "."],
  [".", ".", ".", ".", ".", ".", ".", "."],
  [".", ".", ".", ".", ".", ".", ".", "."],
  ["P", "P", "P", "P", "P", "P", "P", "P"],
  ["R", "N", "B", "Q", "K", "B", "N", "R"],
];

const pieceSymbols = {
  r: "♜",
  n: "♞",
  b: "♝",
  q: "♛",
  k: "♚",
  p: "♟",
  R: "♖",
  N: "♘",
  B: "♗",
  Q: "♕",
  K: "♔",
  P: "♙",
  ".": "",
};

function App() {
  const [board, setBoard] = useState(initialBoard);
  const [selectedSquare, setSelectedSquare] = useState(null);
  const [validMoves, setValidMoves] = useState([]);
  const [turn, setTurn] = useState("white");

  let audioRef = useRef({
    click: null,
  });
  useEffect(() => {
    if (typeof window !== "undefined") {
      audioRef.current.click = new Audio("/public/click.mp3");
    }
  }, []);

  const calculateValidMoves = (piece, row, col) => {
    const moves = [];
    const isWhite = piece === piece.toUpperCase();

    const isValid = (r, c) =>
      r >= 0 &&
      r < 8 &&
      c >= 0 &&
      c < 8 &&
      (board[r][c] === "." ||
        (isWhite
          ? board[r][c] === board[r][c].toLowerCase()
          : board[r][c] === board[r][c].toUpperCase()));

    switch (piece.toLowerCase()) {
      case "p": {
        const direction = isWhite ? -1 : 1;
        const startRow = isWhite ? 6 : 1;

        if (
          isValid(row + direction, col) &&
          board[row + direction][col] === "."
        ) {
          moves.push([row + direction, col]);

          if (
            row === startRow &&
            isValid(row + 2 * direction, col) &&
            board[row + 2 * direction][col] === "."
          ) {
            moves.push([row + 2 * direction, col]);
          }
        }

        if (
          col > 0 &&
          isValid(row + direction, col - 1) &&
          board[row + direction][col - 1] !== "."
        ) {
          moves.push([row + direction, col - 1]);
        }
        if (
          col < 7 &&
          isValid(row + direction, col + 1) &&
          board[row + direction][col + 1] !== "."
        ) {
          moves.push([row + direction, col + 1]);
        }
        break;
      }

      case "r": {
        for (let i = row - 1; i >= 0; i--) {
          if (isValid(i, col)) moves.push([i, col]);
          if (board[i][col] !== ".") break;
        }
        for (let i = row + 1; i < 8; i++) {
          if (isValid(i, col)) moves.push([i, col]);
          if (board[i][col] !== ".") break;
        }
        for (let i = col - 1; i >= 0; i--) {
          if (isValid(row, i)) moves.push([row, i]);
          if (board[row][i] !== ".") break;
        }
        for (let i = col + 1; i < 8; i++) {
          if (isValid(row, i)) moves.push([row, i]);
          if (board[row][i] !== ".") break;
        }
        break;
      }
      case "n": {
        const knightMoves = [
          [row + 2, col + 1],
          [row + 2, col - 1],
          [row - 2, col + 1],
          [row - 2, col - 1],
          [row + 1, col + 2],
          [row + 1, col - 2],
          [row - 1, col + 2],
          [row - 1, col - 2],
        ];
        knightMoves.forEach(([r, c]) => isValid(r, c) && moves.push([r, c]));
        break;
      }
      case "b": {
        for (let i = 1; i < 8; i++) {
          if (!isValid(row + i, col + i)) break;
          moves.push([row + i, col + i]);
          if (board[row + i][col + i] !== ".") break;
        }
        for (let i = 1; i < 8; i++) {
          if (!isValid(row - i, col + i)) break;
          moves.push([row - i, col + i]);
          if (board[row - i][col + i] !== ".") break;
        }
        for (let i = 1; i < 8; i++) {
          if (!isValid(row + i, col - i)) break;
          moves.push([row + i, col - i]);
          if (board[row + i][col - i] !== ".") break;
        }
        for (let i = 1; i < 8; i++) {
          if (!isValid(row - i, col - i)) break;
          moves.push([row - i, col - i]);
          if (board[row - i][col - i] !== ".") break;
        }
        break;
      }
      case "q": {
        moves.length = 0;

        // Rook-like
        for (let i = row - 1; i >= 0; i--) {
          // Upwards
          if (isValid(i, col)) moves.push([i, col]);
          if (board[i][col] !== ".") break;
        }
        for (let i = row + 1; i < 8; i++) {
          // Downwards
          if (isValid(i, col)) moves.push([i, col]);
          if (board[i][col] !== ".") break;
        }
        for (let i = col - 1; i >= 0; i--) {
          // Left
          if (isValid(row, i)) moves.push([row, i]);
          if (board[row][i] !== ".") break;
        }
        for (let i = col + 1; i < 8; i++) {
          // Right
          if (isValid(row, i)) moves.push([row, i]);
          if (board[row][i] !== ".") break;
        }

        for (let i = 1; i < 8; i++) {
          // Down-right
          if (!isValid(row + i, col + i)) break;
          moves.push([row + i, col + i]);
          if (board[row + i][col + i] !== ".") break;
        }
        for (let i = 1; i < 8; i++) {
          // Down-left
          if (!isValid(row + i, col - i)) break;
          moves.push([row + i, col - i]);
          if (board[row + i][col - i] !== ".") break;
        }
        for (let i = 1; i < 8; i++) {
          // Up-right
          if (!isValid(row - i, col + i)) break;
          moves.push([row - i, col + i]);
          if (board[row - i][col + i] !== ".") break;
        }
        for (let i = 1; i < 8; i++) {
          // Up-left
          if (!isValid(row - i, col - i)) break;
          moves.push([row - i, col - i]);
          if (board[row - i][col - i] !== ".") break;
        }
        break;
      }
      case "k": {
        const kingMoves = [
          [row + 1, col],
          [row - 1, col],
          [row, col + 1],
          [row, col - 1],
          [row + 1, col + 1],
          [row + 1, col - 1],
          [row - 1, col + 1],
          [row - 1, col - 1],
        ];
        kingMoves.forEach(([r, c]) => isValid(r, c) && moves.push([r, c]));
        break;
      }
      default:
        break;
    }
    return moves;
  };

  const handleSquareClick = (row, col) => {
    const piece = board[row][col];

    if (selectedSquare) {
      const [prevRow, prevCol] = selectedSquare;
      const selectedPiece = board[prevRow][prevCol];

      const isSameColor =
        piece !== "." &&
        ((selectedPiece === selectedPiece.toUpperCase() &&
          piece === piece.toUpperCase()) ||
          (selectedPiece === selectedPiece.toLowerCase() &&
            piece === piece.toLowerCase()));

      if (!isSameColor && validMoves.some(([r, c]) => r === row && c === col)) {
        const newBoard = board.map((r, i) =>
          r.map((p, j) => {
            if (i === row && j === col) return selectedPiece;
            if (i === prevRow && j === prevCol) return ".";
            return p;
          })
        );
        setBoard(newBoard);
        setSelectedSquare(null);
        setValidMoves([]);
        setTurn(turn === "white" ? "black" : "white");
      } else {
        setSelectedSquare(null);
        setValidMoves([]);
      }
    } else if (
      piece !== "." &&
      ((turn === "white" && piece === piece.toUpperCase()) ||
        (turn === "black" && piece === piece.toLowerCase()))
    ) {
      setSelectedSquare([row, col]);
      setValidMoves(calculateValidMoves(piece, row, col));
      audioRef.current.click.play();
    }
  };

  return (
    <div className="flex justify-center items-center min-w-[100vw] min-h-[100vh] bg-gray-100">
      {/* <div className=" absolute left-[30px] bottom-[50px] ">
        <p className="font-[800] ">Analysis of Algorithms Project</p> <br />
        Muhammad Arhum - 44889
        <br />
        Akrash Bashir - 47571
        <br />
        Muhammad Akbar - 44901
      </div> */}
      <div className="mb-4 px-[15px] py-[10px] bg-[#358cd8] rounded-[5px] flex text-[2rem] absolute top-[50px] left-[30px] min-w-[205px] ">
        <p
          className={`font-[800] mr-[8px] ${
            turn === "white" ? "text-white" : "text-black"
          } `}
        >
          {turn === "white" ? "White's " : "Black's "}
        </p>
        turn
      </div>

      <div className="board">
        {board.map((row, rowIndex) =>
          row.map((piece, colIndex) => (
            <div
              key={`${rowIndex}-${colIndex}`}
              onClick={() => handleSquareClick(rowIndex, colIndex)}
              className={`square ${
                selectedSquare &&
                selectedSquare[0] === rowIndex &&
                selectedSquare[1] === colIndex
                  ? "selected"
                  : ""
              } ${
                validMoves.some(([r, c]) => r === rowIndex && c === colIndex)
                  ? "valid-move"
                  : (rowIndex + colIndex) % 2 === 0
                  ? "bg-slate-300"
                  : "bg-[#358cd8]"
              }`}
            >
              {pieceSymbols[piece]}
            </div>
          ))
        )}
      </div>
    </div>
  );
}

export default App;
