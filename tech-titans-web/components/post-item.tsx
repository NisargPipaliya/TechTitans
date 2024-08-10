import { IoCalendarOutline } from "@/components/icons";
import Link from "next/link";
import { buttonVariants } from "./ui/button";
import { cn } from "@/lib/utils";
import { formatDate } from "@/lib/functions";
import { Tag } from "./tag";
import {
  Card,
  CardContent,
  CardDescription,
  CardFooter,
  CardHeader,
  CardTitle,
} from "@/components/ui/card";

interface PostItemProps {
  slug: string;
  title: string;
  description?: string;
  date: string;
  tags?: Array<string>;
}

export function PostItem({
  slug,
  title,
  description,
  date,
  tags,
}: PostItemProps) {
  return (
    <article className="flex flex-col gap-2 border-b border-border py-3">
      <Card>
        <CardHeader>
          <CardTitle>
            <Link href={"/" + slug}>{title}</Link>
          </CardTitle>
          <CardDescription>
            {tags?.map((tag) => <Tag tag={tag} key={tag} />)}
          </CardDescription>
        </CardHeader>
        <CardContent>
          <p>{description}</p>
        </CardContent>
        <CardFooter>
          <div className="flex w-full flex-row justify-between">
            <dd className="flex items-center gap-1 text-sm font-medium sm:text-base">
              <IoCalendarOutline className="h-4 w-4" />
              <time dateTime={date}>{formatDate(date)}</time>
            </dd>
            <Link
              href={"/" + slug}
              className={cn(buttonVariants({ variant: "link" }), "py-0")}
            >
              Read more →
            </Link>
          </div>
        </CardFooter>
      </Card>
    </article>
  );
}
