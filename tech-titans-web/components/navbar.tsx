import React from "react";
import Link from "next/link";
import { ModeToggle } from "@/components/theme-toggle";
import { FaBookReader } from "@/components/icons";

const Navbar: React.FC = () => {
  return (
    <nav className="align-center flex items-center justify-between bg-white p-4 shadow-md dark:bg-gray-800">
      <div className="flex flex-row content-center text-xl font-bold">
        <FaBookReader className="mr-5 text-3xl" />
        <Link
          href="/"
          className="text-blue-500 contain-content dark:text-blue-300"
        >
          Tech Titans
        </Link>
      </div>
      <div className="flex space-x-4">
        <Link
          href="/"
          className="content-center text-gray-700 dark:text-gray-300"
        >
          Home
        </Link>
        <Link
          href="/posts"
          className="content-center text-gray-700 dark:text-gray-300"
        >
          Posts
        </Link>
        <Link
          href="/about"
          className="content-center text-gray-700 dark:text-gray-300"
        >
          About
        </Link>
        <Link
          href="/contact"
          className="content-center text-gray-700 dark:text-gray-300"
        >
          Contact
        </Link>
        <ModeToggle />
      </div>
    </nav>
  );
};

export default Navbar;
